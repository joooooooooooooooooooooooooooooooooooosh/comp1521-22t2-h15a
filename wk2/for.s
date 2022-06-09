main:

        # t0 is x
        li      $t0, 24
main_for_start_1:
        # x >= 42
        bge     $t0, 42, main_for_end_1

        # print
        li      $v0, 1
        move    $a0, $t0
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 3
        b       main_for_start_1
main_for_end_1:

        jr      $ra
