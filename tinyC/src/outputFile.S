#include "screen.h"
#include "system.h"
.global main

.data
	i: .word 0


	lstring1: .asciz "End of loop\n"
	lstring0: .asciz "i = "
.text

# FunctionDeclaration 
main:
	li $a0, BRIGHT_WHITE
	li $a1, BLACK
	jal set_color
	jal clear_screen




# ForStatement
# AssignmentExpr
	li $t1, 0
	sw $t1, i
.lfor0:
	lw $t1, i
	li $t2, 10
	sle $t1, $t1, $t2
	beqz $t1, .lend_for1

# PrintStatement
	la $a0, lstring0
	jal puts

	lw $t3, i
	move $a0, $t3
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

	lw $t2, i
	addi $t3, $t2, 1
	sw $t3, i

	j .lfor0
.lend_for1: 


# PrintStatement
	la $t0, lstring1
	move $a0, $t0
	jal puts


	li $a0, '\n' 
	jal put_char
	jr $ra
