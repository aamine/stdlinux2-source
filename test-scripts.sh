#!/bin/sh

n_tests=0
failed=0
test_finished() {
    rm -rf tc.*
    echo
    if [ "$failed" = "0" ]
    then
        echo "PASS ($n_tests tests) -- `hostname` / `uname -srm`"
        exit 0
    else
        echo "FAIL ($failed/$n_tests failed) -- `hostname` / `uname -srm`"
        exit 1
    fi
}

print() {
    if [ `/bin/echo -n x` = "-n" ]
    then
        /bin/echo $1'\c'
    else
        /bin/echo -n $1
    fi
}

progress() {
    print '.'
}

begin_test() {
    progress
    n_tests=`expr $n_tests "+" 1`
}

test_failed() {
    failed=`expr $failed "+" 1`
}

assert_equal() {
    begin_test
    _f="no"
    excmd=$1; shift
    mycmd=$1; shift
    eval "$excmd" >tc.out.expected 2>tc.err.expected
    eval "$mycmd" >tc.out.real     2>tc.err.real
    assert_not_coredump || return
    cmp tc.out.real tc.out.expected >/dev/null 2>&1
    if [ "$?" != "0" ]
    then
        echo "stdout differ: \"$excmd\" and \"$mycmd\""
        diff -u tc.out.expected tc.out.real
        echo "----"
        _f="yes"
    fi
    cmp tc.err.real tc.err.expected >/dev/null 2>&1
    if [ "$?" != "0" ]
    then
        echo "stderr differ: \"$excmd\" and \"$mycmd\""
        diff -u tc.err.expected tc.err.real
        echo "----"
        _f="yes"
    fi
    [ "$_f" = "yes" ] && test_failed
}

assert_equal_stdout() {
    begin_test
    _f="no"
    excmd=$1; shift
    mycmd=$1; shift
    eval "$excmd" >tc.out.expected 2>/dev/null
    eval "$mycmd" >tc.out.real     2>/dev/null
    assert_not_coredump || return
    cmp tc.out.real tc.out.expected >/dev/null 2>&1
    if [ "$?" != "0" ]
    then
        echo "stdout differ: \"$excmd\" and \"$mycmd\""
        diff -u tc.out.expected tc.out.real
        echo "----"
        test_failed
    fi
}

assert_stdout() {
    begin_test
    expected=$1; shift
    mycmd=$1; shift
    echo "$expected" > tc.out.expected
    eval "$mycmd" >tc.out.real 2>/dev/null
    assert_not_coredump || return
    cmp tc.out.expected tc.out.real >/dev/null 2>&1
    if [ "$?" != "0" ]
    then
        echo "stdout differ: string \"$expected\" and cmd \"$mycmd\""
        diff -u tc.out.expected tc.out.real
        echo "----"
        test_failed
    fi
}

rm -f core
assert_not_coredump() {
    begin_test
    if [ -f core ]
    then
        echo "core dumped: $mycmd"
        echo "----"
        test_failed
        return 1
    fi
    rm -f core
    return 0
}

assert_not_exist() {
    begin_test
    file=$1; shift
    if [ -f $file ]
    then
        echo "exists: $file"
        echo "----"
        test_failed
        return 1
    fi
}

assert_directory() {
    begin_test
    dir=$1; shift
    if [ ! -d $dir ]
    then
        echo "not directory: $dir"
        echo "----"
        test_failed
        return 1
    fi
        
}

Head() {
    if [ `uname -s` = "SunOS" ]
    then
        :
    else
        head ${@+"$@"}
    fi
}

uidof() {
    id $1 | sed -e 's/=/ /' -e 's/(/ /' | awk '{print $2}'
}

assert_stdout   "argc=1
argv[0]=./args"                 './args'

assert_stdout   "argc=2
argv[0]=./args
argv[1]=x"                      './args x'

assert_stdout   "argc=3
argv[0]=./args
argv[1]=x
argv[2]=y"                      './args x y'

assert_stdout   "Hello, World!" './hello'

assert_stdout   ""              './echo'
assert_stdout   "a"             './echo a'
assert_stdout   "a b c"         './echo a b c'
assert_stdout   "a b c"         './echo a "b c"'
assert_stdout   "a b  c"        './echo a "b  c"'

assert_equal    'cat cat.c'     './cat cat.c'
assert_equal    'cat httpd2.c'  './cat httpd2.c'
assert_equal    'cat cat.c'     './cat2 cat.c'
assert_equal    'cat httpd2.c'  './cat2 httpd2.c'
assert_equal    'cat cat.c'     './cat3 cat.c'
assert_equal    'cat httpd2.c'  './cat3 httpd2.c'
assert_equal    'cat cat.c'     './cat3 < cat.c'
assert_equal    'cat httpd2.c'  './cat3 < httpd2.c'
assert_equal    'cat data.esc'  './cat-escape data.esc0'
assert_equal    'cat cat.c'     './cat4 cat.c'
assert_equal    'cat httpd2.c'  './cat4 httpd2.c'
assert_equal    'cat cat.c'     './cat4 < cat.c'
assert_equal    'cat httpd2.c'  './cat4 < httpd2.c'
assert_equal    'cat data.esc'  './cat4 -e data.esc0'
assert_equal    'cat data.esc'  './cat4 -e < data.esc0'

assert_equal    'Head -n 0 head.c'      './head 0 < head.c'
assert_equal    'head -n 5 head.c'      './head 5 < head.c'
assert_equal    'head -n 999 head.c'    './head 999 < head.c'
assert_equal    'Head -n 0 head.c'      './head2 0 < head.c'
assert_equal    'head -n 5 head.c'      './head2 5 < head.c'
assert_equal    'head -n 999 head.c'    './head2 999 < head.c'
assert_equal    'Head -n 0 head.c'      './head3 -n 0 < head.c'
assert_equal    'head -n 5 head.c'      './head3 -n 5 < head.c'
assert_equal    'head -n 999 head.c'    './head3 -n 999 < head.c'
if [ -f head4 ]; then
assert_equal    'Head -n 0 head.c'      './head4 -n 0 < head.c'
assert_equal    'head -n 5 head.c'      './head4 -n 5 < head.c'
assert_equal    'head -n 999 head.c'    './head4 -n 999 < head.c'
assert_equal    'Head -n 0 head.c'      './head4 --lines=0 < head.c'
assert_equal    'head -n 5 head.c'      './head4 --lines=5 < head.c'
assert_equal    'head -n 999 head.c'    './head4 --lines=999 < head.c'
fi

assert_equal    'tail -0 tail.c'      './tail 0 < tail.c'
assert_equal    'tail -5 tail.c'      './tail 5 < tail.c'
assert_equal    'tail -999 tail.c'    './tail 999 < tail.c'

assert_equal    'grep close head.c'         './grep close head.c'
assert_equal    'grep NOTMATCH head.c'      './grep NOTMATCH head.c'
assert_equal    'grep close /dev/null'      './grep close /dev/null'
assert_equal    'grep close head.c'         './grep close head.c'
assert_equal    'grep "open|close" head.c'  './grep "open|close" head.c'

assert_equal    'grep close head.c'         './grep2 close head.c'
assert_equal    'grep NOTMATCH head.c'      './grep2 NOTMATCH head.c'
assert_equal    'grep close /dev/null'      './grep2 close /dev/null'
assert_equal    'grep close head.c'         './grep2 close head.c'
assert_equal    'grep "open|close" head.c'  './grep2 "open|close" head.c'
assert_equal    'grep -v close head.c'      './grep2 -v close head.c'
assert_equal    'grep -v NOTMATCH head.c'   './grep2 -v NOTMATCH head.c'
assert_equal    'grep CLOSE head.c'         './grep2 CLOSE head.c'
assert_equal    'grep -i CLOSE head.c'      './grep2 -i CLOSE head.c'
assert_equal    './grep2 -i close head.c'   './grep2 -i cLoSe head.c'
print "close" > grep2-tmp
assert_equal    'grep -f grep2-tmp head.c'  './grep2 -f grep2-tmp head.c'
print "" > grep2-tmp
assert_equal    'grep -f grep2-tmp head.c'  './grep2 -f grep2-tmp head.c'

assert_equal    'grep close head.c'         './grep3 close head.c'
assert_equal    'grep NOTMATCH head.c'      './grep3 NOTMATCH head.c'
assert_equal    'grep close /dev/null'      './grep3 close /dev/null'
assert_equal    'grep close head.c'         './grep3 close head.c'
assert_equal    'grep "open|close" head.c'  './grep3 "open|close" head.c'

# FIXME: ln
# FIXME: symlink

touch tc.tmp
./rm tc.tmp
assert_not_exist    tc.tmp
touch tc.tmp1 tc.tmp2 tc.tmp3
./rm tc.tmp*
assert_not_exist    tc.tmp1
assert_not_exist    tc.tmp2
assert_not_exist    tc.tmp3
rm -f tc.tmp*

mkdir -p tc.tmpdir
./rmdir tc.tmpdir
assert_not_exist    tc.tmpdir
mkdir -p tc.tmpdir1 tc.tmpdir2 tc.tmpdir3
./rmdir tc.tmpdir1 tc.tmpdir2 tc.tmpdir3
assert_not_exist    tc.tmpdir1
assert_not_exist    tc.tmpdir2
assert_not_exist    tc.tmpdir3
rm -rf tc.tmpdir*

rm -rf tc.tmpdir
./mkdir tc.tmpdir
assert_not_coredump
assert_directory    tc.tmpdir
rm -rf tc.tmpdir*
./mkdir tc.tmpdir1 tc.tmpdir2 tc.tmpdir3
assert_not_coredump
assert_directory    tc.tmpdir1
assert_directory    tc.tmpdir2
assert_directory    tc.tmpdir3
rm -rf tc.tmpdir*

assert_equal    'ls -a'                 './ls . | sort'
assert_equal    'ls -a /'               './ls / | sort'

assert_equal    'env | grep -v "^_"'    './env | grep -v "^_"'
assert_equal    '/bin/pwd'              './pwd'
assert_equal    '/bin/pwd'              './pwd2'
if [ -f pwd3 ]; then
assert_equal    '/bin/pwd'              './pwd3'
fi

assert_stdout   "id=`uidof root`"       './user root'
assert_stdout   "id=`uidof nobody`"     './user nobody'

assert_equal    "id | awk '{print \$1}'"     "./id | awk '{print \$1}'"
assert_equal    "id | awk '{print \$2}'"     "./id | awk '{print \$2}'"

assert_equal_stdout 'find .'            './traverse .'
assert_equal_stdout 'find ..'           './traverse ..'

print '' > tc.tmp
assert_stdout   "0"                     './wcl tc.tmp'
print 'a' > tc.tmp
assert_stdout   "1"                     './wcl tc.tmp'
echo 'a' > tc.tmp
assert_stdout   "1"                     './wcl tc.tmp'
echo 'a' > tc.tmp
print 'b' >> tc.tmp
assert_stdout   "2"                     './wcl tc.tmp'
echo 'a' > tc.tmp
echo 'b' >> tc.tmp
assert_stdout   "2"                     './wcl tc.tmp'
rm -f tc.tmp

test_finished
