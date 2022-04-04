global _start

section .text
_start:
	mov rax, 1		; system call for write
	mov rdi, 1		; set file descriptor to stdout
	mov rsi, str 	; pass address of str to output
	mov rdx, len 	; size of str
	syscall			; invoke syscall


	mov rax, 60		; system call for exit
	xor rdi, rdi	; set exit code to 0
	syscall			; invoke syscall


section .data
str: DB 'hello',0,0xa
len: equ $-str
