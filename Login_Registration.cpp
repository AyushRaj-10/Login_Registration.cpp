#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool LoggingIn() {
    string username, password, storedUser, storedPass;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read(username + ".txt");
    
    if (!read.is_open()) {
        cout << "User not found!" << endl;
        return false;
    }

    getline(read, storedUser);
    getline(read, storedPass);
    
    if (storedUser == username && storedPass == password) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nEnter your choice:\n1. Registration\n2. Login\n3. Exit\n";
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter username: "; cin >> username;
            cout << "Enter password: "; cin >> password;

            ofstream file(username + ".txt");
            file << username << endl << password;
            file.close();
            
            cout << "Registration successful!\n";
        } 
        else if (choice == 2) {
            if (LoggingIn()) {
                cout << "Login successful!\n";
                break; 
            } else {
                cout << "Incorrect information! Try again.\n";
            }
        } 
        else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
