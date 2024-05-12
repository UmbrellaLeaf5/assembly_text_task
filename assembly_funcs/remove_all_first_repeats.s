  .globl	RemoveAllFirstRepeats
RemoveAllFirstRepeats:
  testq %rdi, %rdi    # s ?= nullptr
  je .RAFRRet         # if (s == nullptr) return;

  movq %rdi, %rbx     # extra_var = s
  pushq %rbx          # push extra_var to stack
  call FirstOf
  popq %rbx           # pop extra_var from stack
  movq %rbx, %rcx     # f ptr is extra_var ptr

  movb %al, %r8b      # f value is %r8b
  movq %rdi, %r9      # mod_str ptr is %r9

.RAFRIter:
  movb (%rdi), %al    # get a byte (char)
  testb %al, %al      # *s ?= '\0'
  je .RAFRRetByTheEnd # if (*s == '\0') *mod_str = '\0'; return;

  cmpb %al, %r8b      # *s ?= f
  je .RAFRToNext      # if (*s == f) continue;

  movb %al, (%r9)     # *mod_str = *s;
  incq %r9            # mod_str++;

.RAFRToNext:
  incq %rdi           # next byte (char)
  jmp .RAFRIter       # continue iteration

.RAFRRet:
  ret

.RAFRRetByTheEnd:
  movb $0, (%r9)
  movq %r9, %rdi     # s = mod_str
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
