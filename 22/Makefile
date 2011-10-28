main.o:main.c
	gcc -c main.c -o main.o
all:main.o cal.o
	gcc main.o cal.o -o app
cal.o:cal.c
	gcc -c cal.c -o cal.o
clean:
	$(RM) *.o
