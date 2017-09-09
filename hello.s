	.file	"hello.c"
	.version	"01.01"
gcc2_compiled.:
.section	.rodata
.LC0:
	.string	"Hello, Linux!"
.text
	.align 4
.globl main
	.type	 main,@function
main:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	pushl $.LC0
	call puts
	addl $16,%esp
	xorl %eax,%eax
	jmp .L2
	.p2align 4,,7
.L2:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe1:
	.size	 main,.Lfe1-main
	.ident	"GCC: (GNU) 2.95.3 20010315 (release)"
