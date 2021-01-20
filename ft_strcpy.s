section .text
	global ft_strcpy

ft_strcpy:
	xor rax, rax
	xor rcx, rcx
	cmp rsi, 0
	je end
loop:
	mov cl, BYTE [rsi + rax]
	mov [rdi + rax], cl
	cmp rcx, 0
	je end
	inc rax
	jmp loop
end:
	mov rax, rdi
	ret
