section .text
	global ft_write
	extern __errno_location

ft_write:
	mov rax, 1
	syscall

	cmp rax, 0
	jl error
	ret

error:
	neg rax
	push rax
	pop rdx
	call __errno_location
	mov [rax], edx
	mov rax, -1
	ret
