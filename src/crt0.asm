GLOBAL _start
EXTERN main
EXTERN exit
_start:
    mov rsp, 0x7FFFFFFFFFF0
    
    call main

    mov rdi, rax
    call exit