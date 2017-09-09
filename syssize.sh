#!/bin/sh

for i in caddr_t clock_t comp_t dev_t fpos_t gid_t ino_t nlink_t off_t pid_t \
	 ptrdiff_t rlim_t ' size_t' ssize_t time_t uid_t
do
	echo "#include <sys/types.h>" | gcc -E - | grep typedef | grep $i
done
