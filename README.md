# LockBox

A password manager built in C that allows users to store and retrieve their passwords to a txt file, *for now*. Users can add, retrieve, and remove password entries.

### To-Do

- ~~Divide the code into header files, logic and main.~~
- Get rid of the logins.txt file because it's a security shit show.
- Allow user to edit master password.
- Implement some stronger encryption.
- Implement pointers and linked list.
- Figure out a way to deploy / release the console app.

### How it works

```
Enter master password: mypassword

Menu:
1. Add a new login
2. View saved logins
3. Update an existing login
4. Delete a saved login
5. Exit
Enter your choice: 1

Enter website name: example.com
Enter username: alice
Enter password: secret@3534
Login added successfully 🤙

Menu:
1. Add a new login
2. View saved logins
3. Update an existing login
4. Delete a saved login
5. Exit
Enter your choice: 2

Saved logins:
example.com - alice

Menu:
1. Add a new login
2. View saved logins
3. Update an existing login
4. Delete a saved login
5. Exit
Enter your choice: 3

Enter website name: example.com
Enter new username: alice@example.com
Enter new password: YOLO@#$3212
Login updated successfully 🤙

Menu:
1. Add a new login
2. View saved logins
3. Update an existing login
4. Delete a saved login
5. Exit
Enter your choice: 2

Saved logins:
example.com - alice@example.com

Menu:
1. Add a new login
2. View saved logins
3. Update an existing login
4. Delete a saved login
5. Exit
Enter your choice: 4

Enter website name: example.com
Login deleted successfully 🤙

Menu:
1. Add a new login
2. View saved logins
3. Update an existing login
4. Delete a saved login
5. Exit
Enter your choice: 2

No logins saved 👎

Menu:
1. Add a new login
2. View saved logins
3. Update an existing login
4. Delete a saved login
5. Exit
Enter your choice: 5

Sayonara 👋
```
