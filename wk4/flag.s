.data
flag:
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

.text
main:
# row in t0
        li      $t0, 0
for_start_1:
        bge     $t0, 6, for_end_1

        # col in t1
        li      $t1, 0
for_start_2:
        bge     $t1, 12, for_end_2
        
        # print flag[row][col]
        # &flag[row] = &flag + row * 12 * sizeof(char)
        la      $t2, flag
        mul     $t3, $t0, 12
        add     $t3, $t2, $t3

        # &flag[row][col] = &flag[row] + col * sizeof(char)
        add     $t4, $t3, $t1

        li      $v0, 11
        lb      $a0, ($t4)
        syscall

        addi    $t1, $t1, 1
        b       for_start_2
for_end_2:

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1
        b       for_start_1
for_end_1:

        li      $v0, 0
        jr      $ra
