#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#define MAX_USERS 100

// Global array to store users
struct user users[MAX_USERS];
// Counter for how many users have been created
int user_count = 0;

// Function to create a new user
void create_user() {
    // Check if user limit is reached
    if (user_count >= MAX_USERS){
        printf("User limit reached!\n");
        return;
    }

    struct user new_user;

    // Get user name input
    printf("Enter your name: ");
    scanf(" %s", new_user.name);

    // Get user password input
    printf("Enter your password: ");
    scanf(" %s", new_user.password);

    // Store new user in the global users array
    users[user_count] = new_user;
    user_count++;

    printf("\nUser created successfully!\n");
}

// Function to display all registered users
void view_users(){
    // Check if there are no users registered
    if (user_count == 0){
        printf("No users registered.\n");
        return;
    }

    // Loop through all users and print their details
    for (int i = 0; i < user_count; i++){
        printf("\nUser %d:\n", i+1);
        printf("Name: %s\n", users[i].name);
        printf("Password: %s\n\n", users[i].password);
    }
}

// Function to display the menu options
void menu() {
    printf("Choose one of the options:\n");
    printf("------------------------\n");
    printf("1 - Create user\n");
    printf("2 - View users\n");
    printf("0 - Exit\n");
    printf("Choice: ");
}

int main() {
    int choice = -1;

    // Main loop to handle menu choices until user exits
    while (choice != 0){
        menu();
        scanf("%d", &choice);

        if (choice == 1) {
            create_user();
        } else if (choice == 2) {
            view_users();
        } else if (choice == 0) {
            printf("Exiting program...\n");
        } else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
