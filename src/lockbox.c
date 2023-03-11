#include "lockbox.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numLogins = 0;
struct Login logins[MAX_LOGINS];

// Save the logins to a file
void saveLoginsToFile()
{
  FILE *f = fopen("./src/logins.txt", "w");
  if (f == NULL)
  {
    printf("Error opening file1\n");
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
  FILE *f = fopen("./src/logins.txt", "r");
  if (f == NULL)
  {
    printf("Error opening file2\n");
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

  printf("Login added successfully 🤙\n");
}

// View saved logins
void viewLogins()
{
  if (numLogins == 0)
  {
    printf("No logins saved 👎\n");
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
    printf("No logins saved 👎\n");
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
      printf("Enter new username: ");
      scanf("%s", logins[i].username);

      printf("Enter new password: ");
      scanf("%s", logins[i].password);

      found = 1;
      break;
    }
  }

  if (!found)
  {
    printf("Login not found 👎\n");
  }
  else
  {
    saveLoginsToFile();
    printf("Login updated successfully 🤙\n");
  }
}

// Delete a saved login
void deleteLogin()
{
  if (numLogins == 0)
  {
    printf("No logins saved 👎\n");
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
    printf("Login not found 👎\n");
  }
  else
  {
    saveLoginsToFile();
    printf("Login deleted successfully 🤙\n");
  }
}