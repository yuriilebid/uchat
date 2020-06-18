#include <unistd.h>
#include <stdio.h>
#include <sqlite3.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

int mx_createdb(const char* str);
int mx_create_table(const char* str);
int mx_insert_data(const char *str, char* name, char* time);
int mx_show_users(const char* str);
int mx_update_data(char* str, char* where, char* id, char* what, char* val);
int mx_delete_table(const char* str, char* table);
int mx_add_user(const char *str, char* login, char* password);
int mx_add_message(const char *str, char* user, char* sender, char* time, char* message);
int mx_show_all_messages(const char* str);

char** mx_get_all_messages_of_user(const char* str, char* user);
bool mx_confirm_users_password(const char* str, char* user, char* password);
char* mx_get_users_last_message(const char* str, char* user);
/* IN PROGRESS...
int mx_confirm_user(const char *str, char* login, char* password);
char** mx_get_users_message(const char *str, char* login);
char* mx_get_last_message(const char *str, char* logn);
*/


