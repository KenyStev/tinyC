#include "screen.h"
#include "system.h"
.global main

.data
	x: .word 0
	y: .word 0


	lstring1: .asciz "Add %d\n"
	lstring4: .asciz "Div %d\n"
	lstring5: .asciz "Mod %d\n"
	lstring3: .asciz "Mul %d\n"
	lstring2: .asciz "Sub %d\n"
	lstring0: .asciz "X = %d, Y = %d\n"
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
	li $t1, 342239392
	sw $t1, x
	move $v0, $t0

# ExpressionStatement
# AssignmentExpr
	li $t2, 342239952
	sw $t2, y
	move $v0, $t1

# PrintStatement
	la $t2, lstring0
	move $a0, $t2
	jal puts
	lw $t2, x
	move $a0, $t2
	jal put_udecimal
	lw $t2, y
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t2, lstring1
	move $a0, $t2
	jal puts
	lw $t2, x
	lw $t3, y
	add $t2, $t2, $t3
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t2, lstring2
	move $a0, $t2
	jal puts
	lw $t2, x
	lw $t3, y
	sub $t2, $t2, $t3
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t2, lstring3
	move $a0, $t2
	jal puts
	lw $t2, x
	lw $t3, y
	move $a0, $t2
	move $a1, $t3
	jal mult
	move $t2, $v0
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t2, lstring4
	move $a0, $t2
	jal puts
	lw $t2, x
	lw $t3, y
	move $a0, $t2
	move $a1, $t3
	addi $sp, -8
	move $a2, $sp
	addi $a3, $sp, 4
	jal divide
	lw $t2, ($a2)
	addi $sp, $sp, 8
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t2, lstring5
	move $a0, $t2
	jal puts
	lw $t2, x
	lw $t3, y
	move $a0, $t2
	move $a1, $t3
	addi $sp, -8
	move $a2, $sp
	addi $a3, $sp, 4
	jal divide
	lw $t2, ($a3)
	addi $sp, $sp, 8
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t2, lstring5
	move $a0, $t2
	jal puts
	li $t2, 'H'
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char
	jr $ra
