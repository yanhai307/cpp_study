	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$10, -8(%rbp)
	movl	$20, -12(%rbp)
	leaq	-8(%rbp), %rdi
	leaq	-12(%rbp), %rsi
	callq	__Z6myswapIiEvRT_S1_    // main函数中的第一次调用模板函数的地方，int类型, 将调用到第34行的地方
	movb	$97, -13(%rbp)
	movb	$98, -14(%rbp)
	leaq	-13(%rbp), %rdi
	leaq	-14(%rbp), %rsi
	callq	__Z6myswapIcEvRT_S1_    // main函数中的第一次调用模板函数的地方，char类型，将调用到第61行的地方
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z6myswapIiEvRT_S1_    ## -- Begin function _Z6myswapIiEvRT_S1_
	.weak_definition	__Z6myswapIiEvRT_S1_
	.p2align	4, 0x90
__Z6myswapIiEvRT_S1_:                   ## @_Z6myswapIiEvRT_S1_
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movl	(%rsi), %eax
	movl	%eax, -20(%rbp)
	movq	-16(%rbp), %rsi
	movl	(%rsi), %eax
	movq	-8(%rbp), %rsi
	movl	%eax, (%rsi)
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rsi
	movl	%eax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z6myswapIcEvRT_S1_    ## -- Begin function _Z6myswapIcEvRT_S1_
	.weak_definition	__Z6myswapIcEvRT_S1_
	.p2align	4, 0x90
__Z6myswapIcEvRT_S1_:                   ## @_Z6myswapIcEvRT_S1_
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movb	(%rsi), %al
	movb	%al, -17(%rbp)
	movq	-16(%rbp), %rsi
	movb	(%rsi), %al
	movq	-8(%rbp), %rsi
	movb	%al, (%rsi)
	movb	-17(%rbp), %al
	movq	-16(%rbp), %rsi
	movb	%al, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
