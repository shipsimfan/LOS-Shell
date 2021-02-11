GLOBAL _start
EXTERN main
EXTERN exit
_start:
    call main

    mov rdi, rax
    call exit