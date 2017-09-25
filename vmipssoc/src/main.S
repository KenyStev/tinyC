#include "screen.h"
#include "system.h"
.global main

.data
	a: .word 0
	b: .word 0
	x: .word 0
	y: .word 0
	z: .word 0


	lstring2: .asciz ") = "
	lstring1: .asciz ", "
	lstring0: .asciz "GCD("
.text

# FunctionDeclaration 
gcd:
	jr $ra
# FunctionDeclaration 
main:
	li $a0, BRIGHT_WHITE
	li $a1, BLACK
	jal set_color
	jal clear_screen




# ExpressionStatement
# AssignmentExpr
	li $t1, 10
	sw $t1, a
	move $v0, $t0

# ExpressionStatement
# AssignmentExpr
	li $t2, 20
	sw $t2, b
	move $v0, $t1

# ExpressionStatement
# AssignmentExpr
	lw $t3, a
	sw $t3, x
	move $v0, $t2

# ExpressionStatement
# AssignmentExpr
	lw $t4, b
	sw $t4, y
	move $v0, $t3

# ExpressionStatement
# AssignmentExpr

	sw , z
	move $v0, $t4

# PrintStatement
	la $a0, lstring0
	jal puts

	lw $t5, a
	move $a0, $t5
	jal put_udecimal
	la $a0, lstring1
	jal puts

	lw $t5, b
	move $a0, $t5
	jal put_udecimal
	la $a0, lstring2
	jal puts

	lw $t5, z
	move $a0, $t5
	jal put_udecimal


	li $a0, '\n' 
	jal put_char
	jr $ra
# FunctionDeclaration 
gcd:

# IfStatement
	lw $t5, b
	li $t6, 0
	seq $t5, $t5, $t6
	beqz $t5, .lelse0



j .lend_if1
.lelse0:



.lend_if1: 

	jr $ra
