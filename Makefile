EXEC := sokac
CC := gcc-12

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
CFLAGS := -g -Wall -lm -fPIC -rdynamic

$(EXEC): $(OBJS)
	mkdir -p bin/
	$(CC) $(OBJS) $(CFLAGS) -o bin/$(EXEC)

%.o: %.c include/%.h
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	-rm bin/$(EXEC)
	-rm src/*.o


