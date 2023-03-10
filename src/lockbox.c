#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGINS 100
#define MAX_WEBSITE_LENGTH 50
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct Login
{
  char website[MAX_WEBSITE_LENGTH];
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
};

int numLogins = 0;
struct Login logins[MAX_LOGINS];

// Save the logins to a file
void saveLoginsToFile()
{
  FILE *f = fopen("logins.txt", "w");
  if (f == NULL)
  {
    printf("Error opening file\n");
    return;
  }

  fprintf(f, "%d\n", numLogins);
  for (int i = 0; i < numLogins; i++)
  {
    fprintf(f, "%s %s %s\n", logins[i].website, logins[i].username, logins[i].password);
  }

  fclose(f);
}

// Load the logins from a file
void loadLoginsFromFile()
{
  FILE *f = fopen("logins.txt", "r");
  if (f == NULL)
  {
    printf("Error opening file\n");
    return;
  }

  fscanf(f, "%d", &numLogins);
  for (int i = 0; i < numLogins; i++)
  {
    fscanf(f, "%s %s %s", logins[i].website, logins[i].username, logins[i].password);
  }

  fclose(f);
}

// Add a new login
void addLogin()
{
  if (numLogins >= MAX_LOGINS)
  {
    printf("Error: maximum number of logins exceeded\n");
    return;
  }

  struct Login newLogin;

  printf("Enter website name: ");
  scanf("%s", newLogin.website);

  printf("Enter username: ");
  scanf("%s", newLogin.username);

  printf("Enter password: ");
  scanf("%s", newLogin.password);

  logins[numLogins] = newLogin;
  numLogins++;

  saveLoginsToFile();

  printf("Login added successfully\n");
}

// View saved logins
void viewLogins()
{
  if (numLogins == 0)
  {
    printf("No logins saved\n");
    return;
  }

  printf("Saved logins:\n");
  for (int i = 0; i < numLogins; i++)
  {
    printf("%s - %s\n", logins[i].website, logins[i].username);
  }
}

// Update an existing login
void updateLogin()
{
  if (numLogins == 0)
  {
    printf("No logins saved\n");
    return;
  }

  char website[MAX_WEBSITE_LENGTH];
  printf("Enter website name: ");
  scanf("%s", website);

  int found = 0;
  for (int i = 0; i < numLogins; i++)
  {
    if (strcmp(logins[i].website, website) == 0)
    {
      printf("Enter new username (or press Enter to keep the same): ");
      scanf("%s", logins[i].username);

      printf("Enter new password (or press Enter to keep the same): ");
      scanf("%s", logins[i].password);

      found = 1;
      break;
    }
  }

  if (!found)
  {
    printf("Login not found\n");
  }
  else
  {
    saveLoginsToFile();
    printf("Login updated successfully\n");
  }
}

// Delete a saved login
void deleteLogin()
{
  if (numLogins == 0)
  {
    printf("No logins saved\n");
    return;
  }

  char website[MAX_WEBSITE_LENGTH];
  printf("Enter website name: ");
  scanf("%s", website);

  int found = 0;
  for (int i = 0; i < numLogins; i++)
  {
    if (strcmp(logins[i].website, website) == 0)
    {
      for (int j = i; j < numLogins - 1; j++)
      {
        logins[j] = logins[j + 1];
      }
      numLogins--;

      found = 1;
      break;
    }
  }

  if (!found)
  {
    printf("Login not found\n");
  }
  else
  {
    saveLoginsToFile();
    printf("Login deleted successfully\n");
  }
}

// Display the main menu
int main()
{
  loadLoginsFromFile();
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
      printf("Goodbye\n");
      break;
    default:
      printf("Invalid choice\n");
      break;
    }
  } while (choice != 5);

  return 0;
}