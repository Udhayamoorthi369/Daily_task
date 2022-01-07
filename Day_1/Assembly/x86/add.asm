

section .text
        global _start       ;must be declared for using gcc
_start:

section .data

sum dword 0
i dword 0

loopfalse dword 8

section .code

.code
main proc


 mov eax,0   ;sum
 mov ebx,0   ;i

startforloop:
cmp ebx, 10  ;check loop condition
jg exit      ; false?exit loop
add eax,ebx  ; sum+=i
inc ebx      ; i++
jmp startforloop ; repeat the loop
exit:

mov eax,loopfalse
main endp
end main



        
