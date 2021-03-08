GLOBAL _start
EXTERN main
_start:
    mov rsp, 0x7FFFFFFFFFF0
    
    call main

    mov rsi, rax
    xor rdi, rdi
    syscall

GLOBAL SystemCall
SystemCall:
    push r10
    mov r10, rcx
    syscall
    pop r10
    
    ret