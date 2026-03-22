#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_CONTACTS 100

typedef struct {
    char name[100];
    char phone[32];
    char email[100];
} Contact;

void addContact(Contact list[], int *count);
void displayContacts(Contact list[], int count);
void searchContact(Contact list[], int count);

#endif