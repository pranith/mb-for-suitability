	.file	"read.c"
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.text
.Ltext0:
	.comm	src,8,8
.globl main
	.type	main, @function
main:
.LFB0:
	.file 1 "read.c"
	.loc 1 7 0
	.cfi_startproc
	pushq	%rbp
.LCFI0:
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
.LCFI1:
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	.loc 1 8 0
	movl	$67108864, -16(%rbp)
	.loc 1 9 0
	mov	-16(%rbp), %eax
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, src(%rip)
	.loc 1 10 0
	movl	$0, -12(%rbp)
	.loc 1 13 0
	movl	$-961633963, -4(%rbp)
	.loc 1 14 0
	movl	$0, -8(%rbp)
	jmp	.L2
.L4:
	.loc 1 16 0
	movq	src(%rip), %rax
	mov	-12(%rbp), %edx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -20(%rbp)
	.loc 1 17 0
	movq	src(%rip), %rax
	movl	-12(%rbp), %edx
	addl	$1, %edx
	mov	%edx, %edx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -24(%rbp)
	.loc 1 18 0
	movq	src(%rip), %rax
	movl	-12(%rbp), %edx
	addl	$2, %edx
	mov	%edx, %edx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -28(%rbp)
	.loc 1 21 0
	addl	$1, -12(%rbp)
	.loc 1 22 0
	movl	-12(%rbp), %eax
	addl	$3, %eax
	cmpl	-16(%rbp), %eax
	jb	.L3
	.loc 1 23 0
	movl	$0, -12(%rbp)
.L3:
	.loc 1 14 0
	addl	$1, -8(%rbp)
.L2:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jb	.L4
	.loc 1 26 0
	movl	$0, %eax
	.loc 1 27 0
	leave
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
.Letext0:
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.quad	.LFB0-.Ltext0
	.quad	.LCFI0-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 8
	.quad	.LCFI0-.Ltext0
	.quad	.LCFI1-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 16
	.quad	.LCFI1-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 16
	.quad	0x0
	.quad	0x0
	.section	.debug_info
	.long	0x12c
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF16
	.byte	0x1
	.long	.LASF17
	.long	.LASF18
	.quad	.Ltext0
	.quad	.Letext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x4
	.byte	0x8
	.byte	0x7
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF8
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF9
	.uleb128 0x5
	.long	0x57
	.uleb128 0x6
	.byte	0x1
	.long	.LASF19
	.byte	0x1
	.byte	0x6
	.long	0x57
	.quad	.LFB0
	.quad	.LFE0
	.long	.LLST0
	.long	0x113
	.uleb128 0x7
	.long	.LASF10
	.byte	0x1
	.byte	0x8
	.long	0x42
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x8
	.string	"i"
	.byte	0x1
	.byte	0xa
	.long	0x42
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x8
	.string	"j"
	.byte	0x1
	.byte	0xa
	.long	0x42
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x7
	.long	.LASF11
	.byte	0x1
	.byte	0xb
	.long	0x7d
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x7
	.long	.LASF12
	.byte	0x1
	.byte	0xb
	.long	0x7d
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0xb
	.long	0x7d
	.byte	0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0x7
	.long	.LASF14
	.byte	0x1
	.byte	0xb
	.long	0x7d
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0xd
	.long	0x42
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.byte	0x0
	.uleb128 0x9
	.string	"src"
	.byte	0x1
	.byte	0x4
	.long	0x129
	.byte	0x1
	.byte	0x9
	.byte	0x3
	.quad	src
	.uleb128 0xa
	.byte	0x8
	.long	0x57
	.byte	0x0
	.section	.debug_abbrev
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x35
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xa
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",@progbits
	.long	0x1f
	.value	0x2
	.long	.Ldebug_info0
	.long	0x130
	.long	0x82
	.string	"main"
	.long	0x113
	.string	"src"
	.long	0x0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0x0
	.value	0x0
	.value	0x0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0x0
	.quad	0x0
	.section	.debug_str,"MS",@progbits,1
.LASF8:
	.string	"long long int"
.LASF3:
	.string	"unsigned int"
.LASF19:
	.string	"main"
.LASF0:
	.string	"long unsigned int"
.LASF9:
	.string	"long long unsigned int"
.LASF18:
	.string	"/home/pranith/progs/mb-for-suitability/basic"
.LASF17:
	.string	"read.c"
.LASF13:
	.string	"dest3"
.LASF1:
	.string	"unsigned char"
.LASF14:
	.string	"dest4"
.LASF16:
	.string	"GNU C 4.4.5"
.LASF6:
	.string	"long int"
.LASF11:
	.string	"dest1"
.LASF12:
	.string	"dest2"
.LASF2:
	.string	"short unsigned int"
.LASF4:
	.string	"signed char"
.LASF10:
	.string	"size"
.LASF15:
	.string	"num_iter"
.LASF5:
	.string	"short int"
.LASF7:
	.string	"char"
	.ident	"GCC: (Debian 4.4.5-8) 4.4.5"
	.section	.note.GNU-stack,"",@progbits
