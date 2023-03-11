# LockBox

A password manager built in C that allows users to store and retrieve their passwords to a txt file, *for now*. Users can add, retrieve, and remove password entries.

### To-Do

- ~~Divide the code into header files, logic and main.~~
- Get rid of the logins.txt file because it's a security shit show.
- Implement some stronger encryption.
- Implement pointers and linked list.
- Figure out a way to deploy / release the console app.

### How it works

```
Enter master password: mypassword

Menu:

    Add a new login
    View saved logins
    Update an existing login
    Delete a saved login
    Exit
    Enter your choice: 1

Enter website name: example.com
Enter username: alice
Enter password: secret

Login added successfully 🤙

Menu:

    Add a new login
    View saved logins
    Update an existing login
    Delete a saved login
    Exit
    Enter your choice: 2

Saved logins:
example.com - alice

Menu:

    Add a new login
    View saved logins
    Update an existing login
    Delete a saved login
    Exit
    Enter your choice: 3

Enter website name: example.com
Enter new username (or press Enter to keep the same): alice@example.com
Enter new password (or press Enter to keep the same): newpassword

Login updated successfully 🤙

Menu:

    Add a new login
    View saved logins
    Update an existing login
    Delete a saved login
    Exit
    Enter your choice: 2

Saved logins:
example.com - alice@example.com

Menu:

    Add a new login
    View saved logins
    Update an existing login
    Delete a saved login
    Exit
    Enter your choice: 4

Enter website name: example.com

Login deleted successfully 🤙

Menu:

    Add a new login
    View saved logins
    Update an existing login
    Delete a saved login
    Exit
    Enter your choice: 2

No logins saved 👎

Menu:

    Add a new login
    View saved logins
    Update an existing login
    Delete a saved login
    Exit
    Enter your choice: 5

Sayonara 👋
```
