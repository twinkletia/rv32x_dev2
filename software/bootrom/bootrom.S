.text 
.globl _boot
_boot:
	csrr a0, mhartid
	# jump to entry point
	la t0, 0x80000000
	jr t0
.align 2
