#include "lockbox.h"
#include <stdio.h>
#include <string.h>

// Display the main menu
int main()
{
    unsigned char stored_hash[SHA256_DIGEST_LENGTH];
    char entered_password[MAX_PASSWORD_LENGTH];

    // read stored hash from file or prompt the user to set it
    FILE* fp = fopen("./src/hash.txt", "rb");
    fread(stored_hash, 1, SHA256_DIGEST_LENGTH, fp);
    if (fp == NULL || fread(stored_hash, 1, SHA256_DIGEST_LENGTH, fp) != SHA256_DIGEST_LENGTH)
    {
        printf("No master password set. Please set the master password:\n");
        printf("Master password: ");
        scanf("%s", entered_password);

        unsigned char entered_hash[SHA256_DIGEST_LENGTH];
        hash_password(entered_password, entered_hash);

        fp = fopen("hash.txt", "wb");
        fwrite(entered_hash, 1, SHA256_DIGEST_LENGTH, fp);
        fclose(fp);

        printf("Master password set successfully.\n");
    }
    fclose(fp);

    // prompt user to enter master password
    printf("Enter master password: ");
    scanf("%s", entered_password);

    // hash entered password and compare with stored hash
    unsigned char entered_hash[SHA256_DIGEST_LENGTH];
    hash_password(entered_password, entered_hash);

    if (memcmp(stored_hash, entered_hash, SHA256_DIGEST_LENGTH) != 0)
    {
        printf("Invalid password\n");
    }

    // password is valid, continue with the program
    printf("Password is valid\n");
    // ...
}


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
      break;
    }
  } while (choice != 5);

  return 0;
}