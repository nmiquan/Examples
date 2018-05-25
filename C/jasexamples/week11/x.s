    .ident  "output of gcc -S x.c"

	.file	"x.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$48, %esp
	movl	$0, -4(%ebp)
	jmp	.L2
.L4:
	movl	-4(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, -44(%ebp,%eax,4)
	addl	$1, -4(%ebp)
.L2:
	movl	$10, -4(%ebp)
	jmp	.L4
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
