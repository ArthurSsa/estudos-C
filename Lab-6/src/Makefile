# Definindo o compilador e as flags
CC = gcc
CFLAGS = -I. -Wall

# Arquivos fonte e executável
SRCS = main.c calculo_investimento.c gerenciamento_investimento.c
OBJS = $(SRCS:.c=.o)
EXEC = programa

# Regra padrão
all: $(EXEC)

# Regra para construir o executável
$(EXEC): $(OBJS)
    $(CC) -o $(EXEC) $(OBJS)

# Regra para criar objetos
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar arquivos gerados
clean:
    rm -f $(EXEC) $(OBJS)
