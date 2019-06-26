__stack = 0x20040000;

ENTRY(ResetISR);

MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00100000
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00040000
}

SECTIONS
{
	.text 0x00000000: 
	{
		_text = .;
		KEEP(*(.isr_vector));
		*(.text*);
		_init = .;
		*(.init*);
		_fini = .;
		*(.fini*);
		*(.eh_frame*);
		*(.rodata*);
	} > FLASH
    .ARM.exidx :
    {
        *(.ARM.exidx*);
    } > FLASH
    _etext = .;
	.data 0x20000000: AT(_etext)
	{
		_data = .;
		*(vtable*);
		*(.data*);
		_edata = .;
		__end__ = .;
	} > SRAM
	.bss :
	{
		__bss_start__ = .;
		*(.bss*);
		*(COMMON);
	    __bss_end__ = .;
		__heap_start__ = .;
	} > SRAM
}
