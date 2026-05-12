; =========================
; Main program
; =========================

LOAD R1 5
LOAD R2 1

CALL 5

LOAD R5 99

JMP 13

; =========================
; Loop function
; =========================

LOAD R0 0

SUB R1 R1 R2

CMP R1 R0

JNE 6

LOAD R3 42

PUSH R3
POP R4

RET