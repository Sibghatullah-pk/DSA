 #include <iostream>
#include <map>
#include <string>
using namespace std;
void addContact(map<string, string> &phoneBook)
{
    string name, phoneNo;
    cout << "enter name";
    cin >> name;
    cout << "enter phoneNumbr";
    cin >> phoneNo;
    phoneBook[name] = phoneNo; // Add or update the contact
    cout << "Contact added/updated successfully.\n";
}
void viewContacts(map<string, string> &phoneBook)
{
    cout << "\nPhone Book Entries:" << endl;
    map<string, string>::iterator i = phoneBook.begin();
    while (i != phoneBook.end())
    {
        cout << i->first << " : " << i->second << endl;
        ++i;
    }
}
void searchContact(map<string, string> &phoneBook)
{

    string name;
    cout << "Enter the name to search: ";
    cin >> name;

    if (phoneBook.find(name) != phoneBook.end())
    {
        cout << "Phone number of " << name << ": " << phoneBook[name] << endl;
    }
    else
    {
        cout << "No entry found for " << name << "." << endl;
    }
}

void deleteContact(map<string, string> &phoneBook)
{
    string name;
    cout << "Enter the name to delete: ";
    getline(cin, name);
    if (phoneBook.erase(name))
    {
        cout << "Contact deleted successfully.\n";
    }
    else
    {
        cout << "No entry found for " << name << ".\n";
    }
}
int main()
{
    map<string, string> phoneBook;
    phoneBook["Ali"] = "123-456-7890";
    phoneBook["me"] = "987-654-3210";
    phoneBook["you"] = "555-666-7777";

    int choice;

    while (true)
    {
        // Display menu
        cout << "\nPhone Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore any leftover input in the buffer

        switch (choice)
        {
        case 1:
            addContact(phoneBook);
            break;
        case 2:
            viewContacts(phoneBook);
            break;
        case 3:
            searchContact(phoneBook);
            break;
        case 4:
            deleteContact(phoneBook);
            break;
        case 5:
            cout << "Exiting phone book. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}