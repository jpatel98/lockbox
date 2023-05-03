// defines the data structure and functions for the lockbox program
#ifndef LOCKBOX_H
#define LOCKBOX_H

// constants
#define MAX_LOGINS 100
#define MAX_WEBSITE_LENGTH 50
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// data structure
struct Login {
    char website[MAX_WEBSITE_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// function prototypes
int numLogins;
struct Login logins[MAX_LOGINS];
void saveLoginsToFile();
void loadLoginsFromFile();
void addLogin();
void viewLogins();
void updateLogin();
void deleteLogin();
void hashPassword(const char *password, char *hash);

#endif
