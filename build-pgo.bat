@echo off
setlocal

set BUILD_DIR=build-pgo
if not "%2"=="" set BUILD_DIR=%2

if /I "%1"=="generate" (
    set PGO=GENERATE
) else if /I "%1"=="use" (
    set PGO=USE
) else (
    echo Usage: %0 {generate^|use} [build-dir]
    echo.
    echo   generate   - build instrumented binary (Phase 1)
    echo   use        - rebuild from profiles (Phase 3)
    echo.
    echo   Phase 2: run the instrumented binary from Phase 1 on
    echo            real workloads, then exit to flush profiles.
    echo.
    echo   Examples:
    echo     %0 generate
    echo     %0 use
    echo     %0 generate build-pgo-i686
    exit /b 1
)

cmake -B "%BUILD_DIR%" -A Win32 -DPGO=%PGO% -DBuildMPEngine=OFF -DBuildMPRdVanilla=OFF -DBuildMPRend2=OFF -DBuildMPGame=OFF -DBuildMPCGame=OFF -DBuildMPUI=OFF -DBuildSPEngine=OFF -DBuildSPGame=OFF -DBuildSPRdVanilla=OFF -DBuildJK2SPEngine=OFF -DBuildJK2SPGame=OFF -DBuildJK2SPRdVanilla=OFF
cmake --build "%BUILD_DIR%" --config Release --target openjkded.x86 -- -m
