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
	cmp rax, 0
	jz end_error
	mov rdi, rax
	pop rsi
	call ft_strcpy
	jmp end

end_error:
	pop rdi
end:
	ret
