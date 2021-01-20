section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	push rdi
	call ft_strlen
	mov rdi, rax
	inc rdi
	call malloc
	mov rdi, rax
	pop rsi
	call ft_strcpy
end:
	ret
