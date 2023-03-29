CC = gcc

CFLAGS = -Wall -Wextra -Werror 

print_module: main_module_entry_point.c print_module.c
	$(CC) $(CFLAGS) -o ../build/Quest_1 main_module_entry_point.c print_module.c -D print_module

clean:
	rm -f *.o

