src = asm.s hello.s
obj = asm.o hello.o
target = asm hello
all:$(target)
$(target):$(obj)
%:%.o
	ld $< -o $@ -lc -dynamic-linker /lib/ld-linux.so.2
$(obj):$(src)
%.o:%.s
	as $< -o $@
