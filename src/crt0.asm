GLOBAL _start
EXTERN main
_start:
    ; Execute(const char* filename)
    ;mov rdi, 3
    ;mov rsi, filename
    ;syscall

    ; DisplayString(const char* string)
    mov rdi, 1
    mov rsi, message
    syscall

    ; ReadKeyInput(char* buffer, size_t bufferSize)
    mov rdi, 2
    mov rsi, buffer
    mov rdx, 2048
    syscall

    ; Exit()
    mov rdi, 0
    mov rsi, 0
    syscall

    .hang:
        jmp .hang

message: db 0x0A, "LOS Shell!", 0x0A, 0x00

buffer: resb 2048