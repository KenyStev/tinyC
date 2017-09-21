#isaula: 4
#kevin: 8
#raim: 12
#x: 16
#test: 17
#$ra: 0
.data:
	lbl1: .asciz "sasas"
	lbl2: .asciz "sasas"
	lbl3: .asciz "sasas"
	lbl4: .asciz "sasas"
	lbl5: .asciz "sasas"

.text:

	main:
		addi $sp, $sp, -21
		sw $ra, ($sp)

		# char test = (char)raim;
		lb $t0, 12($sp)
		sb $t0, 17($sp)

		# division(12, 4);
		li $a0, 12
		li $a1, 4
		jal division
		# int x = division(12, 4);
		sw $v0, 16($sp)

		beq $v0, $zero, .else
		la $t0, lbl1
		sw $t0, 4($sp)

		j for

	.else:
		#makePuto(kevin);
		lw $t0, 8($sp)
		move $a0, $t0
		jal makePuto
		sw $v0, 8($sp)
		#isaula = makePuto(kevin);
		addi $sp, $sp, -4
		li $t0, 0
		sw $t0, ($sp)
	for:
		# i = 0; i < 100;
		lw $t1, ($sp)
		slti $t1, $t1, 100
		beqz $t1, .end_for
		# reverse("otup");
		la $a0, lbl2
		jal reverse
		# $t1 = isaula
		lw $t1, 8($sp)
		# isaula += reverse("otup");
		add $t1, $t1, $v0
		sw $t1, 8($sp)
		# i++
		lw $t1, ($sp)
		addi $t1, $t1, 1
		sw $t1, ($sp)
		j .for

	.end_for:
		add $sp, $sp, 4

	while:
		# isaula == "puto"
		la $t0, lbl2
		lw $t1, 4($sp)
		bne $t0, $t1, .end_while

		# x % 2
		lw $t0, 16($sp)
		move $a0, $t0
		li $a1, 2
		jal mod
		# x % 2 == 0 ? 1
		bnez $v0, .ternary_false
		li $t0, 1
		sw $t0, 8($sp)

		j .ternary2

	.ternary_false:
		# : "celoso";
		la $t0, lbl2
		sw $t0, 8($sp)
	
	.ternary2:
		# x % 2
		lw $t0, 16($sp)
		move $a0, $t0
		li $a1, 2
		jal mod
		# x % 2 == 0 ? 1
		bnez $v0, .ternary2_false
		li $t0, 2
		sw $t0, 8($sp)
		j end_while

	.ternary2_false:
		# : "celoso";
		la $t0, lbl3
		sw $t0, 8($sp)

	.end_while:

	.end_main:
		lw $ra, ($sp)
		addi $sp, $sp, 21

		jr ra