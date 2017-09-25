#include "screen.h"
#include "system.h"
.global main

.data


	lstring0: .asciz "Hello World!\n"
.text

# FunctionDeclaration 
main:
	li $a0, BRIGHT_WHITE
	li $a1, BLACK
	jal set_color
	jal clear_screen


# PrintStatement
	la $t0, lstring0
	move $a0, $t0
	jal puts


	li $a0, '\n' 
	jal put_char
	jr $ra
