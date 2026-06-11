#ifndef TINY_CPU_HPP
#define TINY_CPU_HPP

#include <vector>

#include "cpu/ExecutionUnit.hpp"
#include "cpu/CPUFlags.hpp"
#include "cpu/InstructionMemory.hpp"
#include "cpu/CPUStage.hpp"
#include "cpu/ControlUnit.hpp"
#include "cpu/Datapath.hpp"
#include "cpu/SimpleALU.hpp"

#include "memory/RegisterFile.hpp"
#include "memory/StackMemory.hpp"

class TinyCPU {
    private:
        RegisterFile registerFile;

        ExecutionUnit executionUnit;

        CPUFlags flags;

        StackMemory stackMemory;

        InstructionMemory instructionMemory;

        unsigned int programCounter;

        CPUStage currentStage;

        unsigned long cycleCount;

        Instruction currentInstruction;

        ControlUnit controlUnit;

        ControlSignals currentControlSignals;

        Datapath datapath;

        SimpleALU alu;

        unsigned long instructionsRetired;

    public:
        TinyCPU();

        void loadProgram(const std::vector<Instruction>& instructions);

        void step();

        void run();

        void printState() const;

        CPUStage getCurrentStage() const;

        unsigned long getCycleCount() const;

        void printMicroState() const;

        void tick();

        void halt();

        bool isHalted() const;

        Instruction getCurrentInstruction() const;

        void executeStage();

        void writebackStage();

        void decodeStage();

        void fetchStage();

        void printPipelineState() const;

        
};

#endif