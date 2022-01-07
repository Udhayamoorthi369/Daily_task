

.global _start
_start:
	mov r0,#1;	/*!  i = 0 */
	mov r1,#2;	/*!  j = 2  */
	mov r3,#0;	/*!  sum = 0   */
	mov r0,r1;	/*!  i = j */
	forloop:
	cmp r0,#5;	/*!  i < 5 */
	beq complete	/*! if i greater than 5 goto to end of the code */
	mov r4,r0;	/*! 
	ands r4,#1	
	addeq r3,r3,r0;	/*! if even adding the r0 (i) value to the r3 (sum) */
	add r0,r0,#1;	/*! incrementing r0 (i) value */
	b forloop		/*! goto loop */
	complete:
