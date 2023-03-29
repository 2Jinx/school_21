CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

strlen_tests: strlen.o s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D strlen -o strlen_test.o
	$(CC) strlen.o strlen_test.o -o ./../build/Quest_1 -lm

strcmp_tests: strlen.o s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D strcmp -o strlen_test.o
	$(CC) strlen.o strlen_test.o -o ./../build/Quest_2 -lm

strcpy_tests: strlen.o s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D strcpy -o strlen_test.o
	$(CC) strlen.o strlen_test.o -o ./../build/Quest_3 -lm

strcat_tests: strlen.o s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D strcat -o strlen_test.o
	$(CC) strlen.o strlen_test.o -o ./../build/Quest_4 -lm

strchr_tests: strlen.o s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D strchr -o strlen_test.o
	$(CC) strlen.o strlen_test.o -o ./../build/Quest_5 -lm

strstr_tests : strlen.o s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D strstr -o strlen_test.o
	$(CC) strlen.o strlen_test.o -o ./../build/Quest_6 -lm

strlen.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o strlen.o

clean:
	rm -f *.o


