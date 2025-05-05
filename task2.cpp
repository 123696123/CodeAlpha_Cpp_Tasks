#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, user, pass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (file.is_open()) {
        getline(file, user);
        getline(file, pass);
        if (user == username && pass == password)
            cout << "Login successful!\n";
        else
            cout << "Invalid credentials.\n";
    }
    else {
        cout << "User not found.\n";
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;
    if (choice == 1)
        registerUser();
    else if (choice == 2)
        loginUser();
    else
        cout << "Invalid choice.\n";
    return 0;
}
