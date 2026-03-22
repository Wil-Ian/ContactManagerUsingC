#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_CONTACTS 100

typedef struct {
    char name;
    char phone;
    char email;
} Contact;

void addContact(Contact list[], int *count);
void displayContacts(Contact list[], int count);
void searchContact(Contact list[], int count);

#endif