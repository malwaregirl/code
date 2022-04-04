global _start

section .text


_start:
	push 1
	psuh DB 'h'
	call .print
	jmp .exit


.print:
	push ebp			; Save old base pointer value
	mov ebp, esp		; set new base pointer value
	push edi			; save edi
	push esi			; save esi

	mov rax, 1			; system call for write
	mov rdi, 1			; set file descriptor to stdout
	mov rsi, [ebp + 4]	; string to print
	mov rdx, [ebp + 8]	; length
	syscall

	pop esi				; pop the top element of the stack into esi
	pop edi				; pop the top element of the stack into edi
	mov esp, ebp		; 
	pop ebp				; restore the caller's base pointer value
						; pop ebp from top of stack into ebp
	ret

.exit:
	mov rax, 60		; system call for exit
	xor rdi, rdi	; set exit code to 0
	syscall

section .data



section .bss
buffer:		resb 64	; Reserve 64 bytes