INCLUDES := -I./ -I../ -I../include/
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

%.o: %.S
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

.PHONY: clean

all: env.o print.o printf.o genex.o

clean:
	rm -rf *~ *.o


include ../include.mk

