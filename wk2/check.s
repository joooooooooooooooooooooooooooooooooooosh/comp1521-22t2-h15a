main:
    li  $v0, 4
    la  $a0, my_prompt
    syscall
    
    li  $v0, 5
    syscall
    # t0 is x
    move $t0, $v0
    
    ble  $t0, 46340, main_else
    
    li  $v0, 4
    la  $a0, too_big
    syscall
    
    b   main_end
    
main_else:
    mul  $t1, $t0, $t0
    li   $v0, 1
    move $a0, $t1
    syscall
    
    li   $v0, 11
    li   $a0, '\n'
    syscall

main_end:
    
    jr  $ra
    
.data
my_prompt:
    .asciiz "Enter a number: "
too_big:
    .asciiz "square too big for 32 bits\n"
