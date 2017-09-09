#@range_begin(rules)
CC     = gcc
CFLAGS = -g -Wall
OBJS   = main.o network.o http.o

httpd: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c
	$(CC) -c $(CFLAGS) -o $@ $<

network.o: network.c
	$(CC) -c $(CFLAGS) -o $@ $<

http.o: http.c
	$(CC) -c $(CFLAGS) -o $@ $<
#@range_end(rules)
