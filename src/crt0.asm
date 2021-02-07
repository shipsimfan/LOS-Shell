GLOBAL _start
EXTERN main
_start:
    mov rcx, 0xBADC0DE

    xor rax, rax

    call main

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
    syscall

    .hang:
        jmp .hang

message: db 0x0A, "Hello World!", 0x0A, 0x00

buffer: resb 2048