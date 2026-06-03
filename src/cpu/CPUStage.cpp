#include "cpu/CPUStage.hpp"

const char* cpuStageToString(
    CPUStage stage
) {
    switch (stage) {
        case CPUStage::FETCH:
            return "FETCH";

        case CPUStage::DECODE:
            return "DECODE";

        case CPUStage::EXECUTE:
            return "EXECUTE";

        case CPUStage::WRITEBACK:
            return "WRITEBACK";

        case CPUStage::HALTED:
            return "HALTED";

        default:
            return "UNKNOWN";
    }
}