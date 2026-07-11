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
