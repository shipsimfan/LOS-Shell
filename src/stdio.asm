GLOBAL DisplayString
DisplayString:
    mov rsi, rdi
    mov rdi, 1
    syscall

    ret

GLOBAL DisplayHex
DisplayHex:
    mov rsi, rdi
    mov rdi, 5
    syscall

    ret

GLOBAL ReadLine
ReadLine:
    mov rdx, rsi
    mov rsi, rdi
    mov rdi, 2
    syscall

    ret