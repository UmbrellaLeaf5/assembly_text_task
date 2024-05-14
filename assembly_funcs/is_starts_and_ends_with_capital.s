  .globl	IsStartsAndEndsWithCapital
IsStartsAndEndsWithCapital:
  testq %rdi, %rdi    # s ?= nullptr
  jz .ISAEWC_RetFalse # if (s == nullptr) return false; 

  # ----------------------      check LastOf     ----------------------

  pushq %rdi          # push s on stack
  call LastOf

  pushq %rax          # push c on stack
  movsbl %al, %ecx    # char -> int
  call isupper
  popq %rsi           # pop c from stack
  popq %rdi           # pop s from stack

  testl %eax, %eax    # ? !isupper(c)
  je .ISAEWC_RetFalse # if (!isupper(c)) return false; 

  # ----------------------      check FirstOf    ----------------------

  pushq %rdi          # push s on stack
  call FirstOf

  pushq %rax          # push c on stack
  movsbl %al, %ecx    # char -> int
  call isupper
  popq %rsi           # pop c from stack
  popq %rdi           # pop s from stack

  testl %eax, %eax    # ? !isupper(c)
  jz .ISAEWC_RetFalse # if (!isupper(c)) return false; 

  # -------------------    both isupper == true    --------------------

  movb $1, %al        # c = true
  ret                 # return true

.ISAEWC_RetFalse:
  movb $0, %al        # c = false
  ret                 # return false



FirstOf:
  testq %rdi, %rdi    # s ?= nullptr
  je .FO_Nullptr      # if (s == nullptr) c = '\0';
  movb (%rdi), %r8b   # get a byte (char)
  testb %r8b, %r8b    # *s ?= '\0'
  jne	.FO_NotEqual    # if (*s != '\0') c = *s;

.FO_NotEqual:
  movb %r8b, %al      # c = *s
  ret

.FO_Nullptr:
  movb $0, %al        # c = '\0'
  ret



LastOf:
  testq %rdi, %rdi    # s ?= nullptr
  je .LO_Nullptr      # if (s == nullptr) c = '\0';
  xorb %al, %al       # init: c = '\0'

.LO_Iter:
  movb (%rdi), %r8b   # get a byte (char)
  testb %r8b, %r8b    # *s ?= '\0'
  je .LO_Ret          # if (*s == '\0') return;
  movb %r8b, %al      # else c = *s;
  incq %rdi           # next byte (char)
  jmp .LO_Iter        # continue iteration

.LO_Ret:
  ret

.LO_Nullptr:
  movb $0, %al        # c = '\0'
  ret
