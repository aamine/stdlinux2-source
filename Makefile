CC       = gcc
CFLAGS   = -g -Wall -Wno-parentheses
CPPFLAGS =
TARGETS = hello echo segv args bell \
	cat0 cat cat2 cat3 cat-escape cat4 cat5 getcperf feof-bug \
        wc-l-stdio wc-l-syscall \
	head head2 head3 head4 \
        tail tail2 \
	grep grep2 grep3 array wgrep slice slice2 \
        ls ls2 catdir rm mkdir mkpath rmdir ln symlink mv stat touch chmod chown chgrp traverse \
        mapwrite \
	exec spawn dupread sh1 sh2 \
        sig sigqueue-test isatty trap \
        pwd pwd2 pwd3 env showenv user id timefmt strftime \
        daytime daytimed echoclient \
	httpd httpd2 logging

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
