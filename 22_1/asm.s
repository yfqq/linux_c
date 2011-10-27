#include "/usr/include/bits/syscall.h" 
#include "/usr/include/asm/unistd_32.h" 
.section .data
data_items:
    .long 1, 2, 3, 9, 4, 0
.section .text
    .global _start
str:
    .string "hello\n\x0"
format:
    .string "dest:%d\n\x0"
print_byteset:
    pushl %ebp
    movl %esp, %ebp
    subl $8, %esp
    movl 0x8(%ebp), %eax
    xor %ecx, %ecx
1:
    mov (%eax,%ecx,1), %edx
    cmpl $0x0, %edx 
    jz 1f
    push (%eax)
    push $format  
    call printf
    pop %edx 
    pop %edx 
    inc %ecx
    jmp 1b
1:
    movl %ebp, %esp
    popl %ebp
    ret
_start:
#    pushl $str
#    call printf
#    addl $4, %esp
    pushl $data_items
    call print_byteset
    addl $4, %esp

    movl $7, %edx
    movl $str, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    pushl $0
    call exit
    addl $4, %esp
