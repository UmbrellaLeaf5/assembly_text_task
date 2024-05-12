  .globl	ChangeAllLatinToStar
ChangeAllLatinToStar:
  testq %rdi, %rdi    # s ?= nullptr
  je .CALTSRet        # if (s == nullptr) return; 

.CALTSIter:
  movb (%rdi), %al    # get a byte (char)
  testb %al, %al      # *s ?= '\0'
  je .CALTSRet        # if (*s == '\0') return;

  pushq %rax          # push char on stack
  movsbl %al, %ecx    # char -> int
  call isalpha
  popq %rsi           # pop char from stack

  testl %eax, %eax    # ? !isalpha(char)
  je .CALTSToNext     # if (!isalpha(c)) continue;

  movb $42, (%rdi)     # else: *char = '*';

.CALTSToNext:
  incq %rdi           # next byte (char)
  jmp .CALTSIter      # continue iteration

.CALTSRet:
  ret
