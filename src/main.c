#include "lockbox.h"
#include <stdio.h>
#include <string.h>

// Display the main menu
int main()
{
  char password[50];
  printf("Enter master password: ");
  scanf("%s", password);

  if (strcmp(password, "mypassword") != 0)
  {
    printf("Invalid password\n");
    return 0;
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