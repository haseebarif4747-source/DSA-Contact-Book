#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact {
    string name, phone, email;
    Contact* next;
};

class ContactBook {
    Contact* head;

    char small(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return ch + 32;
        return ch;
    }

    int compare(string a, string b) {
        int i = 0;
        while (a[i] != '\0' && b[i] != '\0') {
            char x = small(a[i]);
            char y = small(b[i]);
            if (x < y) return -1;
            if (x > y) return 1;
            i++;
        }
        if (a[i] == '\0' && b[i] == '\0') return 0;
        if (a[i] == '\0') return -1;
        return 1;
    }

    Contact* findContact(string name) {
        Contact* temp = head;
        while (temp != NULL) {
            if (compare(temp->name, name) == 0)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void insertSorted(string name, string phone, string email) {
        Contact* node = new Contact;
        node->name = name;
        node->phone = phone;
        node->email = email;
        node->next = NULL;

        if (head == NULL || compare(name, head->name) < 0) {
            node->next = head;
            head = node;
            return;
        }

        Contact* temp = head;
        while (temp->next != NULL &&
               compare(temp->next->name, name) <= 0)
            temp = temp->next;

        node->next = temp->next;
        temp->next = node;
    }

    void clearBook() {
        while (head != NULL) {
            Contact* temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    ContactBook() {
        head = NULL;
    }

    ~ContactBook() {
        clearBook();
    }

    void addContact() {
        string name, phone, email;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter phone: ";
        getline(cin, phone);
        cout << "Enter email: ";
        getline(cin, email);

        if (name == "") {
            cout << "Name cannot be empty.\n";
            return;
        }
        if (findContact(name) != NULL) {
            cout << "This contact already exists.\n";
            return;
        }
        insertSorted(name, phone, email);
        cout << "Contact added.\n";
    }

    void displayContacts() {
        if (head == NULL) {
            cout << "Contact book is empty.\n";
            return;
        }

        Contact* temp = head;
        cout << "\n--- CONTACTS ---\n";
        while (temp != NULL) {
            cout << "Name : " << temp->name << '\n';
            cout << "Phone: " << temp->phone << '\n';
            cout << "Email: " << temp->email << "\n\n";
            temp = temp->next;
        }
    }

    void searchContact() {
        string name;
        cout << "Enter name to search: ";
        getline(cin, name);

        Contact* temp = findContact(name);
        if (temp == NULL) {
            cout << "Contact not found.\n";
            return;
        }
        cout << "Name : " << temp->name << '\n';
        cout << "Phone: " << temp->phone << '\n';
        cout << "Email: " << temp->email << '\n';
    }

    void editContact() {
        string name, newName, phone, email;
        cout << "Enter name to edit: ";
        getline(cin, name);

        Contact* found = findContact(name);
        if (found == NULL) {
            cout << "Contact not found.\n";
            return;
        }

        cout << "Enter new name: ";
        getline(cin, newName);
        cout << "Enter new phone: ";
        getline(cin, phone);
        cout << "Enter new email: ";
        getline(cin, email);

        if (newName == "") {
            cout << "Name cannot be empty.\n";
            return;
        }

        Contact* prev = NULL;
        Contact* temp = head;
        while (temp != found) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL)
            head = found->next;
        else
            prev->next = found->next;

        delete found;
        insertSorted(newName, phone, email);
        cout << "Contact updated.\n";
    }

    void deleteContact() {
        string name;
        cout << "Enter name to delete: ";
        getline(cin, name);

        Contact* temp = head;
        Contact* prev = NULL;

        while (temp != NULL && compare(temp->name, name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Contact not found.\n";
            return;
        }

        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        delete temp;
        cout << "Contact deleted.\n";
    }

    void saveToFile() {
        ofstream file("contacts.txt");
        if (!file) {
            cout << "File could not be opened.\n";
            return;
        }

        Contact* temp = head;
        while (temp != NULL) {
            file << temp->name << '\n'
                 << temp->phone << '\n'
                 << temp->email << '\n';
            temp = temp->next;
        }
        file.close();
        cout << "Contacts saved.\n";
    }

    void loadFromFile() {
        ifstream file("contacts.txt");
        if (!file) {
            cout << "No saved file found.\n";
            return;
        }

        clearBook();
        string name, phone, email;
        while (getline(file, name)) {
            if (!getline(file, phone)) break;
            if (!getline(file, email)) break;
            insertSorted(name, phone, email);
        }
        file.close();
        cout << "Contacts loaded.\n";
    }

    void exportCSV() {
        ofstream file("contacts.csv");
        if (!file) {
            cout << "CSV file could not be created.\n";
            return;
        }

        file << "Name,Phone,Email\n";
        Contact* temp = head;
        while (temp != NULL) {
            file << temp->name << ',' << temp->phone << ','
                 << temp->email << '\n';
            temp = temp->next;
        }
        file.close();
        cout << "CSV exported.\n";
    }
};

int main() {
    ContactBook book;
    string choice;
    book.loadFromFile();

    do {
        cout << "\n===== CONTACT BOOK =====\n";
        cout << "This Project was made by HASEEB ARIF.\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Edit Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Save Contacts\n";
        cout << "7. Load Contacts\n";
        cout << "8. Export CSV\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1") book.addContact();
        else if (choice == "2") book.displayContacts();
        else if (choice == "3") book.searchContact();
        else if (choice == "4") book.editContact();
        else if (choice == "5") book.deleteContact();
        else if (choice == "6") book.saveToFile();
        else if (choice == "7") book.loadFromFile();
        else if (choice == "8") book.exportCSV();
        else if (choice == "0") {
            book.saveToFile();
            cout << "Goodbye!\n";
        }
        else cout << "Invalid choice.\n";

    } while (choice != "0");

    return 0;
}
