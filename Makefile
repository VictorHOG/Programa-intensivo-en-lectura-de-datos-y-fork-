clean:
        rm -rf a.out fileutil.o libfileutil.a main io iofork
obj:
        gcc -c fileutil.c -o fileutil.o
lib:
        ar rcs libfileutil.a fileutil.o
io: obj lib
        gcc -static io.c -L. -I. -lfileutil -o io
iofork: obj lib
        gcc -static iofork.c -L. -I. -lfileutil -o iofork
