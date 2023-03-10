#ifndef LOCKBOX_H
#define LOCKBOX_H

#define MAX_LOGINS 100
#define MAX_WEBSITE_LENGTH 50
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct Login {
    char website[MAX_WEBSITE_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

extern int numLogins;
extern struct Login logins[MAX_LOGINS];

void saveLoginsToFile();
void loadLoginsFromFile();
void addLogin();
void viewLogins();
void updateLogin();
void deleteLogin();
void hashPassword(const char *password, char *hash);

#endif
