CC = gcc
CFLAGS = -Wall -fPIC
INCLUDES = -Iinclude
LIBDIR = lib
SRCDIR = src
EXAMPLEDIR = examples

# Archivos fuente
LIB_SRCS = $(SRCDIR)/iteracion.c $(SRCDIR)/newton.c
LIB_OBJS = $(LIB_SRCS:.c=.o)

# Bibliotecas
LIB_STATIC = $(LIBDIR)/libmatematicas.a
LIB_DYNAMIC = $(LIBDIR)/libmatematicas.dll

# Ejecutables
EXAMPLES = $(EXAMPLEDIR)/demo_iteracion.exe $(EXAMPLEDIR)/demo_newton.exe

# Crear directorio lib si no existe
if not exist $(LIBDIR) mkdir $(LIBDIR)

all: $(LIB_STATIC) $(LIB_DYNAMIC) $(EXAMPLES)

# Biblioteca estática
$(LIB_STATIC): $(LIB_OBJS)
	ar rcs $@ $^
	@echo Biblioteca estatica creada: $@

# Biblioteca dinámica (Windows)
$(LIB_DYNAMIC): $(LIB_OBJS)
	gcc -shared -o $@ $^
	@echo Biblioteca dinamica creada: $@

# Compilar objetos
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

# Enlazar ejemplos
$(EXAMPLEDIR)/demo_iteracion.exe: $(EXAMPLEDIR)/demo_iteracion.c $(LIB_STATIC)
	gcc $(INCLUDES) -L$(LIBDIR) $< -lmatematicas -lm -o $@

$(EXAMPLEDIR)/demo_newton.exe: $(EXAMPLEDIR)/demo_newton.c $(LIB_STATIC)
	gcc $(INCLUDES) -L$(LIBDIR) $< -lmatematicas -lm -o $@

# Limpiar
clean:
	del /Q $(SRCDIR)\*.o $(LIBDIR)\*.a $(LIBDIR)\*.dll $(EXAMPLEDIR)\*.exe 2>nul

.PHONY: all clean