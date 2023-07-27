#ifndef LOCKBOX_H
#define LOCKBOX_H

#define MAX_PASSWORD_LENGTH 100
#define MAX_WEBSITE_LENGTH 100
#define MAX_LOGINS 100
#define MAX_HASH_LENGTH 2000

struct Login {
    char website[MAX_WEBSITE_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct Login logins[MAX_LOGINS];
int numLogins;

void hash_password(char* password, unsigned char* hash);
void saveLoginsToFile();
void loadLoginsFromFile();
void addLogin();
void viewLogins();
void updateLogin();
void deleteLogin();
int verifyMasterPassword(char* password, unsigned char* hash);

#endif /* LOCKBOX_H */
