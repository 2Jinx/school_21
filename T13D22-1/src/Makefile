CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

cipher: cipher.o
	$(CC) $(CFLAGS) cipher.c -o ./../build/cipher

cipher.o: cipher.c
	$(CC) $(CFLAGS) -c cipher.c -o cipher.o

clean:
	rm -f *.o	