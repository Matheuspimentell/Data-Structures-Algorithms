/*
  Author: Matheus Pimentel Leal
  Date: 27/10/2023
  Description: 
    This code represents a simple list data structure written in C. 
*/

#include <stdio.h>
#include <stdlib.h>

struct Contact
{
  char *name;
  char *number;
};

int totalContacts = 0;

void addContact(char *name_, char *number_, struct Contact *phoneBook_)
{
  struct Contact contact;
  contact.name = name_;
  contact.number = number_;

  phoneBook_[totalContacts] = contact;
  
  printf("Contact %s, with number: %s added to the phonebook.\n", contact.name, contact.number);

  totalContacts++;
}

void main(int argc, char *argv)
{
  // Allocate memory corresponding to 10 list items
  struct Contact *phoneBook = malloc(10 * sizeof(struct Contact));

  // Fill the phonebook wiht some contacts
  for (int i = 0; i <= 10; i++)
  {
    char *contactName = malloc(25*sizeof(char));
    char *contactNumber = malloc(30*sizeof(char));
    
    printf("Type the name of a contact to add to the phonebook: ");
    scanf("%s", contactName);
    
    printf("Type the number of the contact to add to the phonebook: ");
    scanf("%s", contactNumber);

    addContact(contactName, contactNumber, phoneBook);

    free(contactName);
    free(contactNumber);
  }

  printf("The phonebook is now full. It contains the following contacts:");

  // Print out all the contacts registered on the phonebook
  for(int j = 0; j <= 10; j++)
  {
    printf("Contact %d\n", &j);
    printf("\t name: %s\n", phoneBook[j].name);
    printf("\t number: %s\n\n", phoneBook[j].number);
  }

  // Free up memory use dby the phonebook
  free(phoneBook);
}