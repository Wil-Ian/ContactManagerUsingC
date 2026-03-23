#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"
#include "ui.h"

int main() {
    Contact myContacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (1) {
        displayHeader();
        printf(" 1. Add New Contact\n"); // C is for ADD
        printf(" 2. View All Contacts\n"); // R is for VIEW
        printf(" 3. Change Existing Contact\n"); // U is for CHANGE
        printf(" 4. Remove Contact\n"); // D is for REMOVE
        printf(" 5. Search Database\n");
        printf(" 0. Exit Application\n");
        printDivider();
        printf("Selection: ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            continue;
        }

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
                changeContacts(myContacts, contactCount);
                pressToContinue();
                break;
            case 4: 
                deleteContact(myContacts, &contactCount);
                pressToContinue();
                break;
            case 5:
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