main:
        li      $t0, 0
main_while_1:
        bge     $t0, 5, main_while_end_1

        # x in t1, y in t2
        mul     $t3, $t0, 2
        lh      $t1, numbers($t3)

        sub     $t2, 9, $t0
        mul     $t4, $t2, 2
        lh      $t2, numbers($t4)

        sh      $t2, numbers($t3)
        sh      $t1, numbers($t4)

        addi    $t0, $t0, 1
        b       main_while_1
main_while_end_1:

        # i in t0
        li      $t0, 0
main_while_2:
        bge     $t0, 10, main_while_end_2

        mul     $t1, $t0, 2
        lh      $t4, numbers($t1)
        
        # printf
        li      $v0, 1
        move    $a0, $t4
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1
        b main_while_2

main_while_end_2:

        li      $v0, 0
        jr      $ra


.data
numbers:
        .half 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
