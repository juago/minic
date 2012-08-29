# Add 7+5 and display on console
.text
main:
li $a0, 7
sw $a0, 0($sp)
addiu $sp, $sp, -4

li $a0, 5
lw $t1, 4($sp)
add $a0, $a0, $t1

# Print integer
li $v0, 1
syscall

# exit gracefully
li $v0, 10
syscall
