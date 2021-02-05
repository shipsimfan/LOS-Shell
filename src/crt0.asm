GLOBAL _start
EXTERN main
_start:
    mov rcx, 0xBADC0DE

    xor rax, rax

    call main

    ;mov rdi, 0
    ;syscall

    mov rdi, 1
    mov rsi, message
    syscall

    mov rdi, 2
    mov rsi, buffer
    mov rdx, 2048
    syscall

    .hang:
        jmp .hang

message: db "Hello World!", 0x0A, 0x00

buffer: resb 2048