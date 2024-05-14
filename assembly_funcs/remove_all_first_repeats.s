  .globl	RemoveAllFirstRepeats
RemoveAllFirstRepeats:
  testq %rdi, %rdi     # s ?= nullptr
  je .RAFR_Ret         # if (s == nullptr) return;

  movq %rdi, %rsi      # extra_var = s
  pushq %rsi           # push extra_var to stack
  call FirstOf
  popq %rsi            # pop extra_var from stack
  movq %rsi, %rcx      # f ptr is extra_var ptr

  movb %al, %r8b       # f value is %r8b
  movq %rdi, %r9       # mod_str ptr is %r9

.RAFR_Iter:
  movb (%rdi), %al     # get a byte (char)
  testb %al, %al       # *s ?= '\0'
  je .RAFR_RetByTheEnd # if (*s == '\0') *mod_str = '\0'; return;

  cmpb %al, %r8b       # *s ?= f
  je .RAFR_ToNext      # if (*s == f) continue;

  movb %al, (%r9)      # *mod_str = *s;
  incq %r9             # mod_str++;

.RAFR_ToNext:
  incq %rdi            # next byte (char)
  jmp .RAFR_Iter       # continue iteration

.RAFR_Ret:
  ret

.RAFR_RetByTheEnd:
  movb $0, (%r9)
  movq %r9, %rdi       # s = mod_str
  ret



FirstOf:
  testq %rdi, %rdi     # s ?= nullptr
  je .FO_Nullptr       # if (s == nullptr) c = '\0';
  movb (%rdi), %r8b    # get a byte (char)
  testb %r8b, %r8b     # *s ?= '\0'
  jne	.FO_NotEqual     # if (*s != '\0') c = *s;

.FO_NotEqual:
  movb %r8b, %al       # c = *s
  ret

.FO_Nullptr:
  movb $0, %al         # c = '\0'
  ret
