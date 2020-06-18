#include "db.h"

int main() {
    const char* dir = "/Users/ylebid/Desktop/database/base.db";
    sqlite3* db;

    mx_createdb(dir);
    mx_create_table(dir);
    mx_add_user(dir, "Yurii", "qwerty");
    mx_add_user(dir, "Vlad", "12345678");
    mx_show_users(dir);
    

    printf("\nALL MESSAGES\n\n");

    mx_add_message(dir, "Yurii", "Vlad", "4:56/17/06/2020", "Hello Yura pidr");
    mx_add_message(dir, "Yurii", "Vlad", "4:56/17/06/2020", "Jopa");
    mx_add_message(dir, "Vlad", "Yurii", "4:57/17/06/2020", "Hello Vlad");
    mx_add_message(dir, "Vlad", "Yurii", "4:57/17/06/2020", "last message");
    mx_show_all_messages(dir);

    printf("\nMESSAGES OF SPECIFIC USER\n\n");
    mx_get_all_messages_of_user(dir, "Yurii");
    printf("%d\n", mx_confirm_users_password(dir, "Vlad", "12345678"));
    printf("%s", mx_get_users_last_message(dir, "Vlad"));
	return 0;
}


// mx_update_data(dir, "LOGIN", "Yurii", "PASSWORD", "1234");
// mx_delete_table(dir, "USERS");
// mx_delete_table(dir, "MESSAGES");