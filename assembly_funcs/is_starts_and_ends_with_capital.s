  .globl	IsStartsAndEndsWithCapital
IsStartsAndEndsWithCapital:
  testq %rdi, %rdi    # s ?= nullptr
  je .FONullptr       # if (s == nullptr) c = '\0'; 

  # ----------------------      test LastOf      ----------------------

  pushq %rdi          # push s on stack
  call LastOf

  pushq %rax          # push c on stack
  movsbl %al, %ecx    # char -> int
  call isupper
  popq %rsi           # pop c from stack
  popq %rdi           # pop s from stack

  testl %eax, %eax    # ? !isupper(c)
  je .ISAEWRetFalse   # if (!isupper(c)) return false; 

  # ----------------------      test FirstOf     ----------------------

  pushq %rdi          # push s on stack
  call FirstOf

  pushq %rax          # push c on stack
  movsbl %al, %ecx    # char -> int
  call isupper
  popq %rsi           # pop c from stack
  popq %rdi           # pop s from stack

  testl %eax, %eax    # ? !isupper(c)
  je .ISAEWRetFalse   # if (!isupper(c)) return false; 

  # -------------------    both isupper == true    --------------------

  movb $1, %al        # c = true
  ret                 # return true

.ISAEWRetFalse:
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
