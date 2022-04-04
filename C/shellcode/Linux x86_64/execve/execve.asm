global _start

section .text
_start:
	; Zero registers
	xor rax, rax
	xor rdi, rdi
	xor rdx, rdx

	; Push onto stack
	push rax					; null-terminator because rax is 0.
	mov rbx, 0x68732f2f6e69622f
	push rbx
	mov rdi, rsp 
	mov al, 59					; set systemcall to 59 (execve)
	syscall						; Execute the syscall


	; cleanup and exit
	xor rax, rax
	xor rdi, rdi

	; Set up exit syscall
	mov al, 60			; Syscall for exit
	syscall				; Execute syscall
