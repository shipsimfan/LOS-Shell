ENTRY(main)
SECTIONS {
    BASE_ADDR = 0x100000;
    
    . = BASE_ADDR;

    .text : {
        *(.text)
        *(.rodata)
    }

    . = ALIGN(4096);

    .data : {
        *(.data)
    }

    . = ALIGN(4096);

    .eh_frame : {
        *(.eh_frame)
    }

    . = ALIGN(4096);

    .bss : {
        *(.bss)
        *(COMMON)
    }

    . = ALIGN(4096);
    
    /DISCARD/ : {
        *(.comment)
    }
}