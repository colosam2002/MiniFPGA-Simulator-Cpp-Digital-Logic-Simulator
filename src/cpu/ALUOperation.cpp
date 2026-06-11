#include "cpu/ALUOperation.hpp"

const char* aluOperationToString(
    ALUOperation operation
) {

    switch (operation) {

        case ALUOperation::ADD:
            return "ADD";

        case ALUOperation::SUB:
            return "SUB";

        case ALUOperation::MOV:
            return "MOV";

        default:
            return "NONE";
    }
}