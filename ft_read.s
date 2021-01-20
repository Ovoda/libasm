section .text
	global ft_read
	extern __errno_location

ft_read:
	mov rax, 0
	syscall

	cmp rax, 0
	jl error
	ret

error:
	neg rax
	push rax
	pop rdx
	call __errno_location
	mov [rax], rdx
	mov rax, -1
	ret
