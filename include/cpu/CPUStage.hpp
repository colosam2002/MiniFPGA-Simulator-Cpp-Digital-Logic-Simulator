#ifndef CPU_STAGE_HPP
#define CPU_STAGE_HPP

enum class CPUStage {
    FETCH,
    DECODE,
    EXECUTE,
    WRITEBACK,
    HALTED
};

const char* cpuStageToString(
    CPUStage stage
);

#endif