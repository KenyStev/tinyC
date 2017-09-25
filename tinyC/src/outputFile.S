#include "screen.h"
#include "system.h"
.global main

.data
	count: .word 0
	number: .word 0
	total: .word 0


	lstring0: .asciz "Number ["
	lstring2: .asciz "The total is "
	lstring1: .asciz "] = "
.text

# FunctionDeclaration 
main:
	li $a0, BRIGHT_WHITE
	li $a1, BLACK
	jal set_color
	jal clear_screen






# CallStatement
	lw $v0, MS_COUNTER_REG_ADDR

	move $a0, $v0
	jal rand_seed

# ExpressionStatement
# AssignmentExpr
	li $t1, 0
	sw $t1, total
	move $v0, $t0

# ExpressionStatement
# AssignmentExpr
	li $t2, 0
	sw $t2, count
	move $v0, $t1

# WhileStatement
.lwhile0: 
	lw $t2, count
	li $t3, 3
	slt $t2, $t2, $t3
	beqz $t2, .lend_while1



# ExpressionStatement
# AssignmentExpr
	jal rand

	li $t4, 100
	move $a0, $v0
	move $a1, $t4
	addi $sp, -8
	move $a2, $sp
	addi $a3, $sp, 4
	jal divide
	lw $t4, ($a3)
	addi $sp, $sp, 8
	li $t5, 1
	add $t4, $t4, $t5
	sw $t4, number
	move $v0, $t3

# PrintStatement
	la $a0, lstring0
	jal puts

	lw $t4, count
	move $a0, $t4
	jal put_udecimal
	la $a0, lstring1
	jal puts

	lw $t4, number
	move $a0, $t4
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# ExpressionStatement
# AssignmentExpr
	lw $t5, count
	li $t6, 1
	add $t5, $t5, $t6
	sw $t5, count
	move $v0, $t4

# ExpressionStatement
# AssignmentExpr
	lw $t6, total
	lw $t7, number
	add $t6, $t6, $t7
	sw $t6, total
	move $v0, $t5

	j .lwhile0
.lend_while1: 


# PrintStatement
	la $a0, lstring2
	jal puts

	lw $t2, total
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char
	jr $ra
