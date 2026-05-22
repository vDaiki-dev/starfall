# Nombre del ejecutable
TARGET = starfall

# Compilador y flags
CC = gcc
CFLAGS = -Wall -O2
LIBS = -lncurses

# Regla principal
all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET) $(LIBS)

# Limpieza
clean:
	rm -f $(TARGET)
