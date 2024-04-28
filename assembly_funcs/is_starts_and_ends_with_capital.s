  .globl	IsStartsAndEndsWithCapital
IsStartsAndEndsWithCapital:
  ret

FirstOf:
  testq %rdi, %rdi    # s ?= nullptr
  je .FONullptr       # if (s == nullptr) c = '\0'; 
  movb (%rdi), %r8b   # get a byte (char)
  testb %r8b, %r8b    # *s ?= '\0'
  jne	.FONotEqual     # if (*s != '\0') c = *s; 
.FONotEqual:
  movb %r8b, %al      # c = *s
  ret
.FONullptr:
  movb $0, %al        # c = '\0'
  ret

LastOf:
  testq %rdi, %rdi    # s ?= nullptr
  je .LONullptr       # if (s == nullptr) c = '\0'; 
  xorb %al, %al       # init: c = '\0'
.LOIter:
  movb (%rdi), %r8b   # get a byte (char)
  testb %r8b, %r8b    # *s ?= '\0'
  je .LORet           # if (*s == '\0') return; 
  movb %r8b, %al      # else c = *s;
  incq %rdi           # next byte (char)
  jmp .LOIter         # continue iteration
.LORet:
  ret
.LONullptr:
  movb $0, %al        # c = '\0'
  ret
