# Add 12 % 5 = 2 and display on console
.text
main:
li $a0, 5
sw $a0, 0($sp)
addiu $sp, $sp, -4

li $a0, 12
lw $t1, 4($sp)
div $a0, $a0, $t1
mfhi $a0       # The mod is stored in the high value of register.

# Print integer
li $v0, 1
syscall

# exit gracefully
li $v0, 10
syscall
