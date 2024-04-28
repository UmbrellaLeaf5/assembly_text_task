  .globl	IsStartsAndEndsWithCapital
IsStartsAndEndsWithCapital:
  ret

LastOf:
  xorb %al, %al
.L1:
  movb (%rdi), %r8b
  testb %r8b, %r8b
  je .L2
  movb %r8b, %al 
  incq %rdi
  jmp .L1
.L2:
  ret
