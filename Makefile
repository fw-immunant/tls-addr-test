PHONY: use-lib

libprint-tls-addr.so: prints-tls-addr.c
	gcc -Wall -g -fPIC -shared prints-tls-addr.c -o libprint-tls-addr.so
libprint-tls-addr2.so: prints-tls-addr2.c
	gcc -Wall -g -fPIC -shared prints-tls-addr2.c -o libprint-tls-addr2.so
use-lib: libprint-tls-addr.so libprint-tls-addr2.so use-lib.c
	gcc -Wall -g -L. -lprint-tls-addr -lprint-tls-addr2 use-lib.c -o use-lib

clean:
	rm lib*.so use-lib

test:
	LD_LIBRARY_PATH=. ./use-lib
