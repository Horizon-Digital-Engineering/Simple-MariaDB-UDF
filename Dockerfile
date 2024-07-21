
FROM mariadb:10.5

RUN apt-get update && apt-get install -y \
    build-essential \
    libmysqlclient-dev

COPY string_udf.c /usr/local/src/
COPY Makefile /usr/local/src/
COPY string_udf.sql /docker-entrypoint-initdb.d/

WORKDIR /usr/local/src

RUN make && make install

CMD ["mysqld"]
