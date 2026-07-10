# OpenJK — Server-Side Backward Reconciliation

This fork implements authoritative server-side lag compensation for melee, saber, and projectile hit detection on the Q3-engine.

## How It Works

### Position History Buffer

Every server frame cycles through all active clients and stores their `currentOrigin`, `mins`, `maxs`, and `currentAngles` into a 64-entry circular buffer (`positionHistory[64]`) indexed by `level.time`.

### Backward Reconciliation (Melee/Saber)

When a player attacks, the server uses the attacker's latency to look backward in time, rewinding every other player's bounding box to the position they occupied on the attacker's screen at the moment the attack button was pressed. The weapon trace runs against these reconciled positions, then all players are restored to their current state.

### Projectile Lag Compensation

When a projectile hits a client, the server rewinds all players to the projectile's spawn time and re-traces the shot path. If the re-traced path no longer contacts a valid target, the hit is silently discarded — preventing latency-favored shots.

### Velocity Extrapolation for Dismemberment

Ghoul2 bone lookups use a velocity-adjusted origin:
```
fVSpeed = (|vel.x| + |vel.y| + |vel.z|) * 0.08
properOrigin = ps.origin + (normalizedVel * fVSpeed)
```
This places the severed limb where the client saw the hit, not where the server's present-time skeleton is.

### Client-Side Prediction

The attacking client plays instant sparks/blood effects on attack before the server confirms — hiding latency without modifying the mesh.

### Event-Based Dismemberment

The server sends an `EV_DISMEMBER` event with the limb type and hit origin. The client turns off the limb surface, enables the stub cap, removes the weapon model if the arm is severed, and plays blood FX — all without server-side limb entities.

## Files Changed

| File | Purpose |
|------|---------|
| `codemp/game/g_combat.c` | `G_RollbackWorldToTime`, `G_UnrollbackWorld`, `G_GetDismemberBolt` with velocity offset, hit location to G2_MODELPART mapping |
| `codemp/game/g_local.h` | `entityHistoryFrame_t`, `positionHistory[64]` in `gclient_s` |
| `codemp/game/g_main.c` | Position history save loop in `G_RunFrame` |
| `codemp/game/g_missile.c` | Projectile hit rewind + re-trace in `G_MissileImpact` |
| `codemp/game/bg_public.h` | `EV_DISMEMBER` event, `DISMEMBER_*` bitmask flags |
| `codemp/cgame/cg_event.c` | `EV_DISMEMBER` dispatch |
| `codemp/cgame/cg_effects.c` | `CG_DismemberProp` — surface manipulation, blood FX |
| `codemp/cgame/cg_predict.c` | Client-side spark prediction on attack |
| `codemp/cgame/cg_local.h` | Smoothing fields, `CG_DismemberProp` declaration |
