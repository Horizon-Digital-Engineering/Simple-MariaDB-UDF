
LIBDIR=/usr/lib/mysql/plugin

string_udf.so: string_udf.o
	gcc -shared -o string_udf.so string_udf.o

string_udf.o: string_udf.c
	gcc -fPIC -I/usr/include/mysql -c string_udf.c

install: string_udf.so
	cp string_udf.so $(LIBDIR)

clean:
	rm -f string_udf.o string_udf.so
