CC = fccpx

CFLAGS =

OBJS = vlctl.o show_vl.o

all: vlctl show_vl

vlctl: vlctl.o
	$(CC) $(CFLAGS) vlctl.o -o $@

show_vl: show_vl.o
	$(CC) $(CFLAGS) show_vl.o -o $@

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

distclean: clean
	rm -f vlctl show_vl

