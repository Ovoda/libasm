section .text
    global ft_strcmp

ft_strcmp:
    mov rax, 0
    mov rdx, 0
    mov r9, 0

loop:
    mov dl, BYTE [rsi + r9]
    cmp BYTE [rdi + r9], dl
    jne end
    cmp BYTE [rsi + r9], 0
    je end
    cmp BYTE [rdi + r9], 0
    je end
    inc r9
    jmp loop

end:
    mov al, BYTE [rdi + r9]
    sub rax, rdx
    ret
