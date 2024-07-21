
# MariaDB UDF Example

This repository contains an example of a C User-Defined Function (UDF) for MariaDB. The UDF takes a string as input and returns a string as output.

## Description

- `string_udf.c`: The C source file for the UDF.
- `Makefile`: The makefile to compile the UDF into a shared library.
- `string_udf.sql`: The SQL script to create the UDF in MariaDB.
- `Dockerfile`: The Dockerfile to build an image with MariaDB and compile the UDF.

## Instructions to Compile and Use the UDF

### Prerequisites

- MariaDB installed and running.
- GCC compiler and Make utility installed.

### Step 1: Compile the UDF

1. **Create the Shared Library:**
   Place `string_udf.c`, `Makefile`, and `string_udf.sql` in the same directory. Run the following command to compile the UDF:
   ```sh
   make
   sudo make install
   ```

### Step 2: Load the UDF in MariaDB

1. **Connect to MariaDB Database:**
   Use `mysql` or another MariaDB client to connect to your database.

2. **Create the UDF:**
   Execute the following SQL command to create the UDF:
   ```sql
   CREATE FUNCTION string_udf RETURNS STRING SONAME 'string_udf.so';
   ```

### Step 3: Test the UDF

1. **Test the UDF:**
   Verify that your UDF is working by calling the function in SQL. Run:
   ```sql
   SELECT string_udf('Hello, World!');
   ```
   This should return `Hello, World!` if the UDF is functioning correctly.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
