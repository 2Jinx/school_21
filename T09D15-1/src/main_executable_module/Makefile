CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: build
build: main_executable_module.o data_io.o data_stat.o data_process.o decision.o
	$(CC) $(CFLAGS) main_executable_module.o data_io.o data_stat.o data_process.o decision.o -o ../../build/Quest_5

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c 

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c 

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c 

data_stat.a: data_stat.o
	ar cr data_stat.a data_stat.o

build_with_static: main_executable_module.o data_stat.o
	ar cr data_stat.a data_stat.a main_executable_module.o
	
clean:
	rm *.o *.a

rebuild: clean
	make build