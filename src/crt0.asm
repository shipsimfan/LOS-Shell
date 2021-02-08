GLOBAL _start
EXTERN main
EXTERN exit
_start:
    call main

    call exit

message: db 0x0A, "LOS Shell!", 0x0A, 0x00

buffer: resb 2048