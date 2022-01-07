
.global _start
_start:

mov r0,#0        // sum=0
mov r1,#0       // i=0

.forloop:

cmp r1,#9       // i<9
bgt .lastloop   
add r0,r0,r1    // sum =sum+i
              
add r1,r1,#1    // i++
b .forloop

.lastloop:
