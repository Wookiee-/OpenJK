# OpenJK — banana branch features

## Lag compensation
- **Position history buffer**: 64-entry circular buffer saving all clients' origin/mins/maxs/angles per frame, indexed by `level.time`
- **Melee/saber rewind**: Server rewinds targets to `level.time - attackerPing` on attack, runs trace, restores — hit registers at what attacker saw
- **Projectile lag compensation**: On hit, rewinds all players to projectile spawn time and re-traces; discards hit if re-trace misses
- **Rollback helper**: Client-side visual error smoothing (`predictionErrorOffset` decays over 100ms) + predictive hit checks for instant feedback
- **hitEntityBitMask**: Prevents multi-hit per saber swing per entity

## Duel system
- **Duel culling**: Non-opponent players are ghosted (solid=0 in snapshots, skipped in server traces)
- **`g_multiDuel`** (0/1): Allow multiple simultaneous private duels
- **`g_startHealth` / `g_startArmor`** (default 0): Set health/armor on spawn, duel start, and duel winner
- **`g_duelDistance`** (0/1): 0 = original 1024-unit auto-cancel, 1 = no distance limit

## Build system
- **PGO support**: `-DPGO=GENERATE` / `-DPGO=USE` for MSVC and GCC/Clang
- **build-pgo.bat / build-pgo.sh**: Scripts for PGO build workflow

## Anti-warp / FPS clamping
- **`MIN_FRAME_MSEC` (4ms)**: In `SV_ClientThink`, incoming `cmd->serverTime` deltas are clamped to a minimum of 4ms, enforcing a safe 250 FPS ceiling server-side regardless of client's `com_maxfps` setting
- **`com_maxfps` enforcement**: `SV_UserinfoChanged` intercepts `com_maxfps` from userinfo and forces values >250 or 0 down to 125
- **`cl_maxpackets` enforcement**: Same function forces `cl_maxpackets` to 100 to prevent network packet flooding

## Saber combat overhaul
- **Block Points via STAT_ARMOR**: `STAT_ARMOR` is used as saber blocking stamina (capped at 100)
- **Per-swing hit tracking**: `saberHitHistory[]` array prevents multi-hit per unique weapon swing, reset on new attack sequence
- **Stance-based max combos**: Fast=5, Medium=4, Heavy=3 consecutive swings before forced recovery
- **Swing stamina costs**: Fast=3/2, Medium=6/5, Heavy=12/10 (initial/combo extension) deducted from `STAT_ARMOR`
- **Dynamic absorption**: Saber damage from front absorbs `currentArmor / maxHealth` fraction. At 100 armor: 100% absorb. At 50: 50% absorb, 50% leak. At 0: Guard broken, full health damage. No fixed breakpoints.
- **Backstab/flank**: Hits from behind (dot > -0.2) bypass armor entirely
- **Startup wind-up interrupt**: Hitting a player in early attack frames bypasses armor, breaks their attack, resets combo
- **Perfect parry**: If defender is in a parry/reflect/knockaway state when hit, damage is negated, attacker is staggered 350ms with combo cancelled, attacker loses 10 armor, defender gains `ps->saberRiposteTime = 500ms`
- **Riposte**: Defender's next attack within riposte window plays 1.15x faster (torsoTimer * 0.87), window consumed on use
- **Tick-based regen**: 1000ms tick via `ClientTimerActions`. Standing still/walking (`ps->speed <= 100` and `weaponTime == 0`): +5 HP +5 armor/sec (cap 100). Running (`ps->speed > 100`), airborne, or in combat (`ps->weaponTime > 0`): -3 armor/sec, HP regen frozen
- **Minimum armor chip**: Even at Tier 4 (100% absorb), at least 1 armor is drained per hit to prevent stalemates
- **`g_flipkick`** (0/1): Restores JO chest-kick knockdown against Force channelers
- **`g_gripSpeedScale`** (default 1.0): Multiplier for movement speed while channeling Force Grip
