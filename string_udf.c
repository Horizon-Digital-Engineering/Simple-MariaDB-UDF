
#include <mysql/mysql.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool string_udf_init(UDF_INIT *initid, UDF_ARGS *args, char *message) {
    if (args->arg_count != 1) {
        strcpy(message, "string_udf() requires one argument");
        return 1;
    }
    if (args->arg_type[0] != STRING_RESULT) {
        strcpy(message, "string_udf() requires a string as an argument");
        return 1;
    }
    return 0;
}

void string_udf_deinit(UDF_INIT *initid) {
    // Cleanup if necessary
}

char* string_udf(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error) {
    const char *input = args->args[0];
    *length = args->lengths[0];
    result = strdup(input);
    return result;
}
