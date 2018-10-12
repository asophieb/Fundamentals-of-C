CC = gcc
CFLAGS = -Wall -Werror -ansi -lm
DEBUG = 1

OBJ = Main.o LinkedList.o Login.o User.o Admin.o AddUser.o Validate.o Encrypt.o Log.o

rebuild : clean build

build : $(OBJ)
	$(CC) $(CFLAGS) -DDEBUG=$(DEBUG) -o Bank $(OBJ) 

clean :
	rm *.out *.o