# Regla principal
all:hellomake

# Constantes
OBJS=hellomake.o hellofunc.o
BINARY=hellomake
CC=gcc	
CFLAGS=-I.

# Variable
x = My

# Variable de expansión recursiva
y = $(x) first
z = $(y) Makefile!!!

# Esta regla compila el programa principal.

hellomake: $(OBJS) 
	$(CC) -o $(BINARY) $(OBJS) 
	@echo $(z)

# %.o: %.c Cualquier archivo .c genero un .o
# carpeta1/%.o: carpeta1/%.c

# Limpieza archivo objeto
clean:
	rm -f $(BINARY) $(OBJS)
