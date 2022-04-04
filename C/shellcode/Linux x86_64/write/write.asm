global _start


section .text
_start:
	; clear registers
	xor rax, rax		; clear rax
	xor rdi, rdi		; clear rdi
	xor rdx, rdx		; clear rdx


	; Push onto stack
	push rax			; the null-terminator
	push 0x6c6c6568		; the string lleh

	; set up write syscall
	inc rax			; Incremement rax to set the syscall to write
	inc rdi			; increment rdi to set the fd to stdout
	mov rsi, rsp	; Pass str
	
	; Access the lower 8bits here to remove null bytes
	mov dl, 4		; Length of the string
	syscall			; Execute the syscall


	; cleanup and exit
	xor rax, rax
	xor rdi, rdi

	; Set up exit syscall
	mov AL, 60			; Syscall for exit
	syscall				; Execute syscall
