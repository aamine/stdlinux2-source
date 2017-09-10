CC       = gcc
CFLAGS   = -g -Wall -Wno-parentheses
CPPFLAGS =
TARGETS = hello echo args bell \
	cat0 cat cat2 cat3 cat-escape cat4 cat5 \
	head head2 head3 \
        tail tail2 \
        wc-l-stdio wc-l-syscall \
	grep grep2 grep3 wgrep slice slice2 \
        ls ls2 rm mkdir rmdir ln symlink mv stat touch chmod chown chgrp \
	spawn \
        pwd pwd2 sleep timefmt isatty env \
	httpd \
	sh1 sh2 \
	user id logging \
	sizeof dupread feof-bug ferror-test exec sig \
        daytime echoclient \
	progname array strto segv trap mapwrite memmon \
	getcperf strftime unsignedchar catdir times \
	sigqueue-test showenv traverse daytimed \
	show-vmmap namemax getctty head4 pwd3 httpd2

DLLIB    = -ldl
NETLIB   =

.SUFFIXES:
.SUFFIXES: .c .
.c:
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

all: $(TARGETS)

show-vmmap: show-vmmap.c
	$(CC) $(CFLAGS) $(CPPFLAGS) show-vmmap.c $(DLLIB) -o $@

daytime: daytime.c
	$(CC) $(CFLAGS) daytime.c $(NETLIB) -o $@

daytimed: daytimed.c
	$(CC) $(CFLAGS) daytimed.c $(NETLIB) -o $@

test: all
	@sh test-scripts.sh

clean:
	rm -f $(TARGETS)
