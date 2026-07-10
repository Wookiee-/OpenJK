# OpenJK — Server-Side Backward Reconciliation

## Position History Buffer

Every frame saves all clients' `currentOrigin`, `mins`, `maxs`, `currentAngles` into a 64-entry circular buffer indexed by `level.time`.

## Melee/Saber Backward Reconciliation

On attack, the server rewinds other players to their positions at `level.time - attackerPing`, runs the weapon trace, then restores. This makes the hit register at what the attacker saw on their screen.

## Projectile Lag Compensation

When a projectile hits a client, the server rewinds all players to the projectile's spawn time and re-traces. If the re-traced path misses, the hit is discarded.

## Velocity Extrapolation for Dismemberment

Ghoul2 bone lookups use a velocity-adjusted origin so severed limbs spawn where the client saw the hit, not where the server's current skeleton is:

```
fVSpeed = (|vel.x| + |vel.y| + |vel.z|) * 0.08
properOrigin = ps.origin + (normalizedVel * fVSpeed)
```

## Client Prediction

Attacking client plays instant sparks before server confirms. Mesh is not modified until server validation.

## Event-Based Dismemberment

Server sends `EV_DISMEMBER` with limb type and hit origin. Client turns off the limb surface, enables the stub cap, removes weapon if arm severed, plays blood FX. No server-side limb entities.

## Files

| File | What |
|------|------|
| `codemp/game/g_combat.c` | `G_RollbackWorldToTime`, `G_UnrollbackWorld`, `G_GetDismemberBolt` velocity offset, hit location mapping |
| `codemp/game/g_local.h` | `entityHistoryFrame_t`, `positionHistory[64]` in `gclient_s` |
| `codemp/game/g_main.c` | History save loop |
| `codemp/game/g_missile.c` | Projectile rewind + re-trace |
| `codemp/game/bg_public.h` | `EV_DISMEMBER`, `DISMEMBER_*` flags |
| `codemp/cgame/cg_event.c` | `EV_DISMEMBER` dispatch |
| `codemp/cgame/cg_effects.c` | `CG_DismemberProp` — surface on/off, blood FX |
| `codemp/cgame/cg_predict.c` | Client-side attack spark prediction |
| `codemp/cgame/cg_local.h` | Smoothing fields, declaration |
