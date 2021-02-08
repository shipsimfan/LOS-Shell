GLOBAL exec
exec:
    mov rsi, rdi
    mov rdi, 3
    syscall

    ret

GLOBAL waitPID
waitPID:
    mov rdx, rsi
    mov rsi, rdi
    mov rdi, 4
    syscall

    ret