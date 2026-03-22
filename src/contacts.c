#include <stdio.h>
#include <string.h>
#include "../include/contacts.h"

void addContact(Contact list[], int *count) {
    if (*count < MAX_CONTACTS) {
        printf("\nEnter Name: ");
        // Removed the 's' after [^\n] and added explicit array access
        scanf(" %[^\n]", list[*count].name);
        printf("Enter Phone: ");
        scanf("%s", list[*count].phone);
        printf("Enter Email: ");
        scanf("%s", list[*count].email);
        (*count)++;
        printf("\nContact saved successfully!\n");
    } else {
        printf("\nError: Contact list is full!\n");
    }
}

void displayContacts(Contact list[], int count) {
    if (count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }
    printf("\n--- ALL CONTACTS ---\n");
    for (int i = 0; i < count; i++) {
        // Ensure we are passing the character arrays
        printf("%d. %s | %s | %s\n", i + 1, list[i].name, list[i].phone, list[i].email);
    }
}

void searchContact(Contact list[], int count) {
    char term;
    printf("\nEnter name to search: ");
    scanf(" %[^\n]", term);

    for (int i = 0; i < count; i++) {
        // strstr needs two pointers (strings), which list[i].name provides
        if (strstr(list[i].name, term) != NULL) { 
            printf("\nFound: %s - %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("\nContact not found.\n");
}