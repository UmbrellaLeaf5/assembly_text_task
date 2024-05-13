  .globl	ChangeAllLatinToStar
ChangeAllLatinToStar:
  testq %rdi, %rdi    # s ?= nullptr
  je .CALTS_Ret        # if (s == nullptr) return; 

.CALTS_Iter:
  movb (%rdi), %al    # get a byte (char)
  testb %al, %al      # *s ?= '\0'
  je .CALTS_Ret        # if (*s == '\0') return;

  pushq %rax          # push char on stack
  movsbl %al, %ecx    # char -> int
  call isalpha
  popq %rsi           # pop char from stack

  testl %eax, %eax    # ? !isalpha(char)
  je .CALTS_ToNext     # if (!isalpha(char)) continue;

  movb $42, (%rdi)     # else: *char = '*';

.CALTS_ToNext:
  incq %rdi           # next byte (char)
  jmp .CALTS_Iter      # continue iteration

.CALTS_Ret:
  ret
