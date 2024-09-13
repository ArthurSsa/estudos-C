CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/calculo_investimento.c src/gerenciamento_investimento.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = investimentos

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) -o $@ $^

clean:
    rm -f $(OBJ) $(TARGET)


// Com esse Makefile, você pode compilar o projeto usando o comando make na pasta do projeto.