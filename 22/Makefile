all:main.o cal.o
	gcc main.o cal.o -o app
%.o:%.c
	gcc $< -c -o $@
clean:
	rm -f *.o
	rm -f app
