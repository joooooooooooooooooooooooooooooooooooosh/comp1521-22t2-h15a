main:
        li      $v0, 4
        la      $a0, my_prompt
        syscall

        li      $v0, 5
        syscall
        # t0 is x
        move    $t0, $v0

        # t1 is y
        mul     $t1, $t0, $t0

        # print(%d)
        li      $v0, 1
        move    $a0, $t1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall
        
        # return
        jr      $ra

        .data
my_prompt:
        .asciiz "Enter a number: "
