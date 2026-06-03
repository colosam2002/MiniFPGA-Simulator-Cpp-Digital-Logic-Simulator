#include "cpu/TinyCPU.hpp"

#include <iostream>

TinyCPU::TinyCPU()
    : instructionMemory(),
      registerFile(8, 8),
      stackMemory(16),
      flags(),
      executionUnit(registerFile, flags, stackMemory),
      programCounter(0),
      currentStage(CPUStage::FETCH),
      cycleCount(0),
      executionResult(0),
      operandA(0),
      operandB(0),
      currentInstruction{
            Opcode::LOAD,
            0,
            0,
            0,
            0
        }
{}
void TinyCPU::loadProgram(const std::vector<Instruction>& instructions) {
    currentStage = CPUStage::FETCH;
    operandA = 0;
    operandB = 0;
    cycleCount = 0;
    executionResult = 0;
    instructionMemory.loadProgram(instructions);
    programCounter = 0;

    instructionMemory.printProgram();
}

void TinyCPU::step() {

    if (programCounter >= instructionMemory.getProgramSize()) {
        std::cout << "Program finished" << std::endl;
        return;
    }

    Instruction instruction = instructionMemory.fetch(programCounter);

    std::cout << "--------------------------------" << std::endl;

    std::cout
        << "Program Counter = "
        << programCounter
        << std::endl;

    std::cout
        << "Executing: "
        << opcodeToString(instruction.opcode)
        << std::endl;

    std::cout
        << "--------------------------------"
        << std::endl;

    ExecutionResult result = executionUnit.execute(instruction, programCounter);

    registerFile.printRegisters();

    std::cout << std::endl;

    flags.printFlags();

    std::cout << std::endl;

    stackMemory.printStack();

    std::cout << std::endl;

    std::cout
        << "SP = "
        << stackMemory.getStackPointer()
        << std::endl;

    std::cout << std::endl;

    if (result.jumpRequested) {
        std::cout
        << "Jumping to instruction "
        << result.jumpAddress
        << std::endl;
        programCounter = result.jumpAddress;
    }
    else {
        ++programCounter;
    }
}

void TinyCPU::run() {

    while (programCounter < instructionMemory.getProgramSize()) {
        step();
    }
}

void TinyCPU::printState() const {

    std::cout
        << std::endl;

    std::cout
        << "================================"
        << std::endl;

    std::cout
        << "FINAL CPU + STACK STATE"
        << std::endl;

    std::cout
        << "================================"
        << std::endl;

    std::cout
        << "Program Counter = "
        << programCounter
        << std::endl;

    std::cout
        << "Program Size = "
        << instructionMemory.getProgramSize()
        << std::endl;
    
    std::cout
        << "Total Cycles: "
        << cycleCount
        << std::endl;

    std::cout
        << std::endl;

    registerFile.printRegisters();

    std::cout
        << std::endl;

    flags.printFlags();

    std::cout << std::endl;

    stackMemory.printStack();

    std::cout << std::endl;

    std::cout
        << "SP = "
        << stackMemory.getStackPointer()
        << std::endl;
    std::cout
        << std::endl;
}

CPUStage TinyCPU::getCurrentStage() const {
    return currentStage;
}

unsigned long TinyCPU::getCycleCount() const {
    return cycleCount;
}

void TinyCPU::printMicroState() const {

    std::cout
        << "================================"
        << std::endl;

    std::cout
        << "Cycle: "
        << cycleCount
        << std::endl;

    std::cout
        << "Stage: "
        << cpuStageToString(currentStage)
        << std::endl;

    std::cout
        << "PC: "
        << programCounter
        << std::endl;

    std::cout
        << "Instruction: "
        << opcodeToString(
               currentInstruction.opcode
           )
        << std::endl;

    printPipelineState();

    std::cout
            << "WRITEBACK -> R"
            << currentInstruction.destination
            << " = "
            << executionResult
            << std::endl;

    registerFile.printRegisters();

    std::cout
        << "================================"
        << std::endl;
}

void TinyCPU::tick() {

    ++cycleCount;

    switch (currentStage) {

        case CPUStage::FETCH:

            fetchStage();

            if (
                currentStage
                !=
                CPUStage::HALTED
            ) {

                currentStage =
                    CPUStage::DECODE;
            }

            break;
        case CPUStage::DECODE:

            decodeStage();

            currentStage =
                CPUStage::EXECUTE;

            break;

        case CPUStage::EXECUTE:

            executeStage();

            currentStage =
                CPUStage::WRITEBACK;

            break;

        case CPUStage::WRITEBACK:

            writebackStage();

            currentStage =
                CPUStage::FETCH;

            ++programCounter;

            break;

        case CPUStage::HALTED:

            break;
    }
}

void TinyCPU::halt() {
    currentStage = CPUStage::HALTED;
}

bool TinyCPU::isHalted() const {
    return currentStage == CPUStage::HALTED;
}

Instruction TinyCPU::getCurrentInstruction() const {
    return currentInstruction;
}

void TinyCPU::executeStage() {

    switch (currentInstruction.opcode) {

        case Opcode::LOAD:

            executionResult =
                currentInstruction.immediate;

            break;

        case Opcode::MOV:

            executionResult = operandA;

            break;

        case Opcode::ADD:

            executionResult = operandA + operandB;

            break;

        case Opcode::SUB:

            executionResult = operandA - operandB;

            break;

        default:

            break;
    }
}

void TinyCPU::writebackStage() {

    switch (currentInstruction.opcode) {


        case Opcode::LOAD:

            registerFile.writeRegister(
                currentInstruction.destination,
                executionResult
            );

            break;

        case Opcode::MOV:

            registerFile.writeRegister(
                currentInstruction.destination,
                executionResult
            );

            break;

        case Opcode::ADD:

            registerFile.writeRegister(
                currentInstruction.destination,
                executionResult
            );

            break;

        case Opcode::SUB:

            registerFile.writeRegister(
                currentInstruction.destination,
                executionResult
            );

            break;

        default:

            break;
    }
}

void TinyCPU::decodeStage() {

    switch (currentInstruction.opcode) {

        case Opcode::MOV:

            operandA =

                registerFile.readRegister(
                    currentInstruction.source1
                );

            break;

        case Opcode::ADD:

            operandA =

                registerFile.readRegister(
                    currentInstruction.source1
                );

            operandB =

                registerFile.readRegister(
                    currentInstruction.source2
                );

            break;

        case Opcode::SUB:

            operandA =

                registerFile.readRegister(
                    currentInstruction.source1
                );

            operandB =

                registerFile.readRegister(
                    currentInstruction.source2
                );

            break;

        default:

            break;
    }
}

void TinyCPU::fetchStage() {

    if (
        programCounter
        >=
        instructionMemory.getProgramSize()
    ) {

        currentStage =
            CPUStage::HALTED;

        return;
    }

    currentInstruction =
        instructionMemory.fetch(
            programCounter
        );
}

void TinyCPU::printPipelineState() const {

    std::cout
        << "IR: "
        << opcodeToString(
               currentInstruction.opcode
           )
        << std::endl;

    std::cout
        << "Operand A: "
        << operandA
        << std::endl;

    std::cout
        << "Operand B: "
        << operandB
        << std::endl;

    std::cout
        << "Execution Result: "
        << executionResult
        << std::endl;
}