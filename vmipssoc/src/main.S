#include "screen.h"
#include "system.h"
.global main

.data
	x: .word 0
	y: .word 0


	lstring1: .asciz ", Y = "
	lstring2: .asciz "Add "
	lstring5: .asciz "Div "
	lstring6: .asciz "Mod "
	lstring4: .asciz "Mul "
	lstring3: .asciz "Sub "
	lstring0: .asciz "X = "
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
	jal rand

	li $t1, 100
	move $a0, $v0
	move $a1, $t1
	addi $sp, -8
	move $a2, $sp
	addi $a3, $sp, 4
	jal divide
	lw $t1, ($a3)
	addi $sp, $sp, 8
	li $t2, 1
	add $t1, $t1, $t2
	sw $t1, x
	move $v0, $t0

# ExpressionStatement
# AssignmentExpr
	jal rand

	li $t2, 100
	move $a0, $v0
	move $a1, $t2
	addi $sp, -8
	move $a2, $sp
	addi $a3, $sp, 4
	jal divide
	lw $t2, ($a3)
	addi $sp, $sp, 8
	li $t3, 1
	add $t2, $t2, $t3
	sw $t2, y
	move $v0, $t1

# PrintStatement
	la $a0, lstring0
	jal puts

	lw $t2, x
	move $a0, $t2
	jal put_udecimal
	la $a0, lstring1
	jal puts

	lw $t2, y
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $a0, lstring2
	jal puts

	lw $t2, x
	lw $t3, y
	add $t2, $t2, $t3
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $a0, lstring3
	jal puts

	lw $t2, x
	lw $t3, y
	sub $t2, $t2, $t3
	move $a0, $t2
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $a0, lstring4
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
	la $a0, lstring5
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
	la $a0, lstring6
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
	la $a0, lstring6
	jal puts

	li $t2, 'H'
	move $a0, $t2
	jal put_char


	li $a0, '\n' 
	jal put_char
	jr $ra
