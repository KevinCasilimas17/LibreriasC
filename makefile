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
LIB_DYNAMIC = $(LIBDIR)/libmatematicas.so

# Ejecutables
EXAMPLES = $(EXAMPLEDIR)/demo_iteracion $(EXAMPLEDIR)/demo_newton

# Crear directorio lib si no existe
$(shell mkdir -p $(LIBDIR))

all: $(LIB_STATIC) $(LIB_DYNAMIC) $(EXAMPLES)

# Biblioteca estática
$(LIB_STATIC): $(LIB_OBJS)
	ar rcs $@ $^
	@echo "✅ Biblioteca estática creada: $@"

# Biblioteca dinámica
$(LIB_DYNAMIC): $(LIB_OBJS)
	$(CC) -shared -o $@ $^
	@echo "✅ Biblioteca dinámica creada: $@"

# Compilar objetos
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Enlazar ejemplos con biblioteca estática
$(EXAMPLEDIR)/demo_iteracion: $(EXAMPLEDIR)/demo_iteracion.c $(LIB_STATIC)
	$(CC) $(INCLUDES) -L$(LIBDIR) $< -lmatematicas -lm -o $@

$(EXAMPLEDIR)/demo_newton: $(EXAMPLEDIR)/demo_newton.c $(LIB_STATIC)
	$(CC) $(INCLUDES) -L$(LIBDIR) $< -lmatematicas -lm -o $@

# Ejecutar con biblioteca dinámica
run_dynamic:
	LD_LIBRARY_PATH=$(LIBDIR) ./$(EXAMPLEDIR)/demo_iteracion

# Limpiar
clean:
	rm -f $(SRCDIR)/*.o $(LIBDIR)/*.a $(LIBDIR)/*.so $(EXAMPLES)

# Instalar bibliotecas (opcional)
install:
	sudo cp $(LIBDIR)/*.a /usr/local/lib/
	sudo cp $(LIBDIR)/*.so /usr/local/lib/
	sudo cp include/*.h /usr/local/include/

.PHONY: all clean run_dynamic install