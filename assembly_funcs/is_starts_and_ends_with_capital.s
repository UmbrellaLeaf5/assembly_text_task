  .globl	IsStartsAndEndsWithCapital
IsStartsAndEndsWithCapital:
  testq %rdi, %rdi    # s ?= nullptr
  je .FONullptr       # if (s == nullptr) c = '\0'; 

  # ----------------------      test LastOf      ----------------------

  pushq %rdi          # store s on stack
  call LastOf

  pushq %rax          # store c on stack
  movsbl %al, %ecx    # char -> int
  call isupper
  popq %rsi           # restore c
  popq %rdi           # and s from stack

  testl %eax, %eax    # !isupper(c)
  jne .ISAEWRet

  # ----------------------      test FirstOg     ----------------------

  pushq %rdi          # store s on stack
  call FirstOf

  pushq %rax          # store c on stack
  movsbl %al, %ecx    # char -> int
  call isupper
  popq %rsi           # restore c
  popq %rdi           # and s from stack

  testl %eax, %eax    # !isupper(c)
  jne .ISAEWRet

  # ----------------------      both isupper     ----------------------

  movb $1, %al        # c = true
  ret                 # return true

.ISAEWRet:
  movb $0, %al        # c = false
  ret                 # return false

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
