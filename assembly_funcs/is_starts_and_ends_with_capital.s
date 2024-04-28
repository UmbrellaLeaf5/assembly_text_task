  .globl	IsStartsAndEndsWithCapital
IsStartsAndEndsWithCapital:
  ret

FirstOf:
  movb (%rdi), %r8b   # get a byte
  testb %r8b, %r8b    # *s ?= '\0'
  jne	.FONotEqual     # if (*s != '\0') c = *s; 
.FONotEqual:
  movb %r8b, %al
  ret

LastOf:
  xorb %al, %al       # init: c = 0
.LOIter:
  movb (%rdi), %r8b   # get a byte
  testb %r8b, %r8b    # *s ?= '\0'
  je .LORet           # if (*s == '\0') return; 
  movb %r8b, %al      # else c = *s;
  incq %rdi           # next byte
  jmp .LOIter         # continue iteration
.LORet:
  ret
