# OpenJK — Changelog (banana branch)

## banana branch commits

- **07b8d7c1** Enforce one hit per player per saber swing via `hitEntityBitMask`
  - Added `hitEntityBitMask[4]` (128 bits) to `gclient_s`/`gentity_s` to track which entities have been hit during a single saber swing
  - Saber swing collision checks skip entities already marked as hit, preventing multi-hit on a single swing
  - Bitmask is cleared on new saber attack

- **898ff3b7** Add projectile lag compensation using position history rollback
  - On projectile impact, rewinds all players to the projectile's spawn time via `G_RollbackWorldToTime`
  - Re-traces the projectile path from its historical position; if the re-traced path misses, the hit is discarded
  - Prevents projectile hits on targets that weren't actually at the impact location from the shooter's perspective

- **e982db1e** Server-side lag compensation rollback
  - Added `entityHistoryFrame_t` and `positionHistory[64]` circular buffer indexed by `level.time`
  - Each frame saves all clients' `currentOrigin`, `mins`, `maxs`, `currentAngles` after `ClientEndFrame`
  - `G_RollbackWorldToTime(targetTime)`: searches history buffer and temporarily rewinds other players to their position at `targetTime`
  - `G_UnrollbackWorld()`: restores all players to their current position
  - Used by melee/saber combat: rewinds to `level.time - attackerPing` so hit registration uses what the attacker saw

 - **b8774e46** Rollback helper: visual error smoothing + predictive hit checks
  - Added `predictionErrorOffset`/`predictionErrorTime` to `centity_t` for client-side visual smoothing
  - In `CG_CalcEntityLerpPositions`: stores position deltas < 64 units as `predictionErrorOffset`, decays to zero over 100ms to avoid snapping
  - `CG_CheckPredictiveWeaponHit`: client-side box trace against target's interpolated position for instant hit feedback before server confirmation

- **14e8684e** Duel culling — non-opponent players ghosted during duels
  - `DuelCull()` in server checks `duelInProgress`/`duelIndex` to return 0 (solid) or 2 (ghost)
  - Hooked into `SV_ClipMoveToEntities` for server-side collision bypass
  - Hooked into `SV_BuildClientSnapshot` to set `solid = 0` on entity states

- **8ed3c590** Client-side duel render cull (reverted, server-side solid=0 sufficient)

- **a0e80171** Drop client-side render cull for duels

- **2ad970b6** PGO build support
  - `-DPGO=GENERATE` / `-DPGO=USE` in CMakeLists.txt
  - MSVC: `/GL` + `/LTCG:PGINSTRUMENT` / `/LTCG:PGOPTIMIZE`
  - GCC/Clang: `-fprofile-generate` / `-fprofile-use`
  - `build-pgo.bat` and `build-pgo.sh` scripts

- **fa0ab94c** Add `g_multiDuel` cvar (default 0)
  - When 0: only one pair can duel at a time (original behavior)
  - When 1: multiple pairs can duel simultaneously

- **f59ada90** Add `g_startHealth` / `g_startArmor` cvars (default 0 = disabled)
  - Applied on spawn (entering from spectator)
  - Applied at the start of a private duel (both participants)
  - Winner gets restored to `g_startHealth` / `g_startArmor` at duel end

- **g_duelDistance** cvar (default 1024)
  - Controls max distance between duelists before duel is auto-cancelled
  - Set to 0 to disable the distance limit entirely
