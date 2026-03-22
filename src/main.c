#include <stdio.h>
#include <string.h>
#include "../include/contacts.h"

int main() {
    Contact myContacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (1) {
        displayHeader();
        printf(" 1. Add New Contact\n");
        printf(" 2. View All Contacts\n");
        printf(" 3. Search Database\n");
        printf(" 0. Exit Application\n");
        printDivider();
        printf("Selection: ");
        
        if (scanf("%d", &choice) != 1) break; // Basic error handling

        switch (choice) {
            case 1: 
                addContact(myContacts, &contactCount); 
                pressToContinue();
                break;
            case 2: 
                displayContacts(myContacts, contactCount); 
                pressToContinue();
                break;
            case 3: 
                searchContact(myContacts, contactCount); 
                pressToContinue();
                break;
            case 0: 
                displayFooter();
                exit(0);
            default: 
                printf("\nInvalid selection!\n");
                pressToContinue();
        }
    }
    return 0;
}