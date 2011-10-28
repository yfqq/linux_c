src = $(wildcard *.c)
obj = a.o b.o
target = a b
all:$(target)

%:%.o
	gcc $< -o $@

%.o:%.c
	gcc $< -c -o $@
