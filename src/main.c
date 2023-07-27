#include "lockbox.h"
#include <stdio.h>
#include <string.h>

// Display the main menu
int main()
{
    unsigned char masterPasswordHash[MAX_HASH_LENGTH];
    char masterPassword[MAX_PASSWORD_LENGTH];

    // Read stored hash from file or prompt the user to set it
    FILE* fp = fopen("./src/hash.txt", "rb");
    if (fp == NULL || fread(masterPasswordHash, 1, MAX_HASH_LENGTH, fp) != MAX_HASH_LENGTH)
    {
        printf("No master password set. Please set the master password:\n");
        printf("Master password: ");
        scanf("%s", masterPassword);

        hash_password(masterPassword, masterPasswordHash);

        fp = fopen("hash.txt", "wb");
        fwrite(masterPasswordHash, 1, MAX_HASH_LENGTH, fp);
        fclose(fp);

        printf("Master password set successfully.\n");
    }
    fclose(fp);

    // Prompt user to enter master password
    char entered_password[MAX_PASSWORD_LENGTH];
    printf("Enter master password: ");
    scanf("%s", entered_password);

    // Hash entered password and compare with stored hash
    // unsigned char entered_hash[MAX_HASH_LENGTH];
    // hash_password(entered_password, entered_hash);

    int passwordVerified = 0;
while (!passwordVerified)
{

    if (strcmp(entered_password, "0") == 0)
    {
        return 0;
    }

    passwordVerified = verifyMasterPassword(entered_password, masterPasswordHash);

    if (!passwordVerified)
    {
        printf("Invalid password! Enter master password (enter 0 to exit): ");
        scanf("%s", entered_password);
    }
}

    // Password is valid, continue with the program
    printf("Password is valid\n");

    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add a new login\n");
        printf("2. View saved logins\n");
        printf("3. Update an existing login\n");
        printf("4. Delete a saved login\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        // Calling the functions using switch case
        switch (choice)
        {
            case 1:
                addLogin();
                break;
            case 2:
                viewLogins();
                break;
            case 3:
                updateLogin();
                break;
            case 4:
                deleteLogin();
                break;
            case 5:
                printf("Sayonara 👋\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
