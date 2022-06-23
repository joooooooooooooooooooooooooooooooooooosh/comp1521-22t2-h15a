# ra is in kernel
main:
main_prologue:
        begin
        push    $ra

main_body:
        # z in t0
        li      $a0, 11
        li      $a1, 13
        li      $a2, 17
        li      $a3, 19
        jal     sum4 # sets $ra to next instruction
        move    $t0, $v0

        #printf
        li      $v0, 1
        move    $a0, $t0
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

main_epilogue:
        pop     $ra
        end

        jr      $ra

sum4:
sum4_prologue:
        begin
        push    $ra
        push    $s0
        push    $s2
        push    $s1

sum4_body:
        move    $s1, $a2
        move    $s2, $a3
        # sum2(a, b)
        jal     sum2
        move    $s0, $v0

        # sum2(c, d)
        move    $a0, $s1
        move    $a1, $s2
        jal     sum2
        move    $t1, $v0

        move    $a0, $s0
        move    $a1, $t1
        jal     sum2

sum4_epilogue:
        pop     $s1
        pop     $s2
        pop     $s0
        pop     $ra
        end

        jr      $ra

sum2:
        li      $t0, 100
        li      $a2, 100
        add     $v0, $a0, $a1
        jr      $ra
