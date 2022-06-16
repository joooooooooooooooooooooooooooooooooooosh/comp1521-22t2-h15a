main:
        # i in t0
        li      $t0, 0
main_while:
        bge     $t0, 10, main_while_end
        # &(numbers[i]) = &numbers + i * sizeof(numbers[0])
        # &numbers + i * 4
        # e.g. numbers @ 0x1000
        # numbers[0] @   0x1000
        # numbers[1] @   0x1004
        # numbers[2] @   0x1008

        # approach 1:
        # la      $t1, numbers
        # mul     $t2, $t0, 4
        # add     $t3, $t1, $t2
        # lw      $t4, ($t3)

        # approach 2
        mul     $t1, $t0, 4
        lw      $t4, numbers($t1)
        
        # printf
        li      $v0, 1
        move    $a0, $t4
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1
        b main_while

main_while_end:

        li      $v0, 0
        jr      $ra


.data
numbers:
        .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
