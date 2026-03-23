#include <stdio.h>
#include <string.h>
#include "contacts.h" 

void addContact(Contact list[], int *count) {
    if (*count < MAX_CONTACTS) {
        printf("\nEnter Name: ");
        scanf(" %99[^\n]", list[*count].name);
        printf("Enter Phone: ");
        scanf(" %31s", list[*count].phone);
        printf("Enter Email: ");
        scanf(" %99s", list[*count].email);
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
        printf("%d. %s | %s | %s\n", i + 1, list[i].name, list[i].phone, list[i].email);
    }
}

void changeContacts(Contact list[], int count) {
    char term[100];
    printf("\nEnter contact number to change: ");
    scanf("%31s", term);

    if (term[0] != '0' || term[1] != '9' || strlen(term) != 11) { // assume that we are using the philippine format (09XX-XXX-YYYY)
        printf("\nInvalid contact number.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].phone, term) == 0) {
            printf("\nEnter new Name: ");
            scanf(" %99[^\n]", list[i].name);
            printf("Enter new Email: ");
            scanf(" %99s", list[i].email);
            printf("\nContact updated successfully!\n");
            return;
        }
    }
    printf("\nContact not found.\n");
}

void deleteContact(Contact list[], int *count) {
    char term[100];
    printf("\nEnter contact number to delete: ");
    scanf("%31s", term);

    if (term[0] != '0' || term[1] != '9' || strlen(term) != 11) { // ph format(09XX-XXX-YYYY)
        printf("\nInvalid contact number.\n");
        return;
    }

    for (int i = 0; i < *count; i++) {
        if (strcmp(list[i].phone, term) == 0) {
            for (int j = i; j < *count - 1; j++) {
                list[j] = list[j + 1];
            }
            (*count)--;
            printf("\nContact deleted successfully!\n");
            return;
        }
    }
    printf("\nContact not found.\n");
}

void searchContact(Contact list[], int count) {
    char term[100];
    printf("\nEnter name to search: ");
    scanf(" %99[^\n]", term);

    for (int i = 0; i < count; i++) {
        if (strstr(list[i].name, term) != NULL) {
            printf("\nFound: %s - %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("\nContact not found.\n");
}