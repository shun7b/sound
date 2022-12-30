CC=gcc
COMAND=sound
OBJS= app.o parameter.o

$(COMAND):$(OBJS)

	$(CC) -o $@ $^ -lm

.c .o:
	$(CC) -c -o $@ $<

PHONE: clean
clean:
	rm -f $(COMAND) $(OBJS)