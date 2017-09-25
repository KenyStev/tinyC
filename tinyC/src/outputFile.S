#include "screen.h"
#include "system.h"
.global main

.data


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





# PrintStatement
	la $t0, lstring0
	move $a0, $t0
	jal puts
	lw $t0, x
	move $a0, $t0
	jal put_udecimal
	lw $t0, y
	move $a0, $t0
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t0, lstring1
	move $a0, $t0
	jal puts
	lw $t0, x
	lw $t1, y
	add $t0, $t0, $t1
	move $a0, $t0
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t0, lstring2
	move $a0, $t0
	jal puts
	lw $t0, x
	lw $t1, y
	sub $t0, $t0, $t1
	move $a0, $t0
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t0, lstring3
	move $a0, $t0
	jal puts
	lw $t0, x
	lw $t1, y
	move $a0, $t0
	move $a1, $t1
	jal mult
	move $t0, $v0
	move $a0, $t0
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t0, lstring4
	move $a0, $t0
	jal puts
	lw $t0, x
	lw $t1, y
	move $a0, $t0
	move $a1, $t1
	addi $sp, -8
	move $a2, $sp
	addi $a3, $sp, 4
	jal divide
	lw $t0, ($a2)
	addi $sp, $sp, 8
	move $a0, $t0
	jal put_udecimal


	li $a0, '\n' 
	jal put_char

# PrintStatement
	la $t0, lstring5
	move $a0, $t0
	jal puts
	lw $t0, x
	lw $t1, y
	move $a0, $t0
	move $a1, $t1
	addi $sp, -8
	move $a2, $sp
	addi $a3, $sp, 4
	jal divide
	lw $t0, ($a3)
	addi $sp, $sp, 8
	move $a0, $t0
	jal put_udecimal


	li $a0, '\n' 
	jal put_char
	jr $ra
