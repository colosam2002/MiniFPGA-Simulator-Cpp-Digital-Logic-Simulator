#ifndef EXECUTION_RESULT_HPP
#define EXECUTION_RESULT_HPP

struct ExecutionResult {
    bool jumpRequested;

    unsigned int jumpAddress;
};

#endif