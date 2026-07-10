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
