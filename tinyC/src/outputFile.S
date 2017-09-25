#include "screen.h"
#include "system.h"
.global main

.data


.text

main:
	li $a0, BRIGHT_WHITE
	li $a1, BLACK
	jal set_color
	jal clear_screen

	jr $ra