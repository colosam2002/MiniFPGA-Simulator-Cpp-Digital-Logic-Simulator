#include <iostream>

#include "cpu/ProgramLoader.hpp"
#include "cpu/TinyCPU.hpp"

int main() {

    TinyCPU cpu;

    auto program =
        ProgramLoader::loadProgram(
            "examples/pipeline_test.asm"
        );
    cpu.loadProgram(program);

    for (int i = 0; i < 20; ++i) {

        cpu.printMicroState();

        cpu.tick();

        if (cpu.isHalted()) {
            break;
        }
    }

    return 0;
}