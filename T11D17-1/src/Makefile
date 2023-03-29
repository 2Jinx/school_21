CC = gcc
CFLAGS = -Wextra -Werror -Wall -std=c11

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.c -o ./../build/Quest_1

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c -o dmanager_module.o

clean:
	rm -f *.o