#include "db.h"

static int mx_strlen(char *s) {
    int counter = 0;

    while(s[counter])
        counter++;
    return counter;
}

static char *mx_strcpy(char *dst, char *src) {
    int counter = 0;

    while(src[counter]) {
        dst[counter] = src[counter];
        counter++;
    }
    dst[counter] = '\0';
    return dst;
}

static char *mx_strnew(int size) {
    char *memory = malloc(size + 1);

    if (memory == NULL)
        return NULL;
    for (int i = 0; i < size + 1; i++)
        memory[i] = '\0';
    return memory;
}

static char *mx_strjoin(char *s1, char *s2) {
    if(s1 == NULL && s2 == NULL) return NULL;

    if(s1 == NULL) {
        int len      = mx_strlen(s2);
        char *result = mx_strnew(len);
        result       = mx_strcpy(result ,s2);
        return result;
    }
    if(s2 == NULL) {
        int len      = mx_strlen(s1);
        char *result = mx_strnew(len);
        result       = mx_strcpy(result, s1);
        return result;
    }
    else {
        int len1 = mx_strlen(s1);
        int len2 = mx_strlen(s2);
        char *cat_str  = mx_strnew(len1 + len2);

        for(int i = 0; i < len1; i++)
            cat_str[i] = s1[i];
        for(int i = len1; i < len1 + len2; i++)
            cat_str[i] = s2[i - len1];
        return cat_str;
    }
}

static char* mx_pack_string_in_double_dots(char* str) {
    char *new_str = mx_strnew(mx_strlen(str) + 2);
    int i = 0;

    *(new_str) = 34;
    for(; i < mx_strlen(str); i++) {
    	*(new_str + i + 1) = *(str + i);
    }
    *(new_str + i + 1) = 34;
    return new_str;
}

static char** mx_callback(void* not_used, int argc, char** argv, char** az_con_name) {
	for(int i = 0; i < argc; i++) {
		printf("%s: %s\n", az_con_name[i], argv[i]);
	}
	return argv;
}

static char **mx_new_strarr(int size) {
    char **arr = (char **)malloc(size + 1);
    char *msg;

    if (arr == NULL) {
        msg = "malloc error\n";
        write(2, msg, (int)strlen(msg));
        exit(1);
    }
    arr[size] = NULL;
    return arr;
}

static char** mx_add_to_arr(char** arr, char* str, int index) {
	*(arr + index) = mx_strnew(mx_strlen(str));

    for(int i = 0; i < mx_strlen(str); i++) {
    	*(*(arr + index) + i) = *(str + i);
    }
    return arr;
}

char** mx_get_all_messages_of_user(const char* str, char* user) {
	sqlite3 *db;
	sqlite3_open(str, &db);
	char* sql = "SELECT MESSAGE, TIME FROM MESSAGES WHERE USER=";
	sqlite3_stmt *res;
    char** message_arr = mx_new_strarr(1024);
    int index = 0;

	user = mx_pack_string_in_double_dots(user);
    sql = mx_strjoin(sql, user);
	sql = mx_strjoin(sql, ";");
	sqlite3_prepare_v2(db, sql, -1, &res, 0);
	sqlite3_step(res);

    while(sqlite3_column_text(res, 0) != NULL) {
        message_arr = mx_add_to_arr(message_arr, sqlite3_column_text(res, 0), index);
        sqlite3_step(res);
        index++;
    }
    *(message_arr + index) = NULL;
    sqlite3_finalize(res);
    sqlite3_close(db);
	return message_arr;
}


















