.data
string1: .asciiz "Print this.\n"

.text
main:
li $v0, 4
la $a0 string1
syscall

# Exit the program gracefully
li $v0 10
syscall
