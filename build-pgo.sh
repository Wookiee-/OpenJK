#!/bin/sh
set -e

BUILD_DIR="${2:-build-pgo}"
TOOLCHAIN="cmake/Toolchains/linux-i686.cmake"
TARGET="openjkded.i386"

case "$1" in
    generate)
        PHASE=GENERATE
        ;;
    use)
        PHASE=USE
        ;;
    *)
        echo "Usage: $0 {generate|use} [build-dir]"
        echo ""
        echo "  generate  — build instrumented openjkded.i386 (Phase 1)"
        echo "  use       — rebuild openjkded.i386 from profiles (Phase 3)"
        echo ""
        echo "  Phase 2: run the instrumented binary from Phase 1 on"
        echo "           real workloads, then exit to flush profiles."
        echo ""
        echo "  Examples:"
        echo "    $0 generate"
        echo "    ./build-pgo/openjkded.i386 +map mymap +quit"
        echo "    $0 use"
        exit 1
        ;;
esac

cmake -B "$BUILD_DIR" \
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" \
    -DPGO="$PHASE" \
    -DCMAKE_BUILD_TYPE=Release \
    -DBuildMPEngine=OFF \
    -DBuildMPRdVanilla=OFF \
    -DBuildMPRend2=OFF \
    -DBuildMPGame=OFF \
    -DBuildMPCGame=OFF \
    -DBuildMPUI=OFF \
    -DBuildSPEngine=OFF \
    -DBuildSPGame=OFF \
    -DBuildSPRdVanilla=OFF \
    -DBuildJK2SPEngine=OFF \
    -DBuildJK2SPGame=OFF \
    -DBuildJK2SPRdVanilla=OFF

cmake --build "$BUILD_DIR" --target "$TARGET" -- -j$(nproc)
