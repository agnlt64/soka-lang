UNAME_S = $(shell uname -s)
EXEC := sokac
CC := gcc

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
CFLAGS := -g -Wall -lm -fPIC -rdynamic
	
ifeq ($(UNAME_S), Darwin)
	CC = gcc-12
endif

$(EXEC): $(OBJS)
	mkdir -p bin/
	$(CC) $(OBJS) $(CFLAGS) -o bin/$(EXEC)

%.o: %.c include/%.h
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	-rm bin/$(EXEC)
	-rm src/*.o


