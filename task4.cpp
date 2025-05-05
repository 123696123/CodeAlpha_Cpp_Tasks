#include <iostream>
#include <map>
using namespace std;

class Account {
    string name;
    int accNo;
    double balance;
public:
    Account() : name(""), accNo(0), balance(0) {}  // Added default constructor
    Account(string n, int a, double b) : name(n), accNo(a), balance(b) {}

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited: " << amt << endl;
    }

    void withdraw(double amt) {
        if (amt > balance)
            cout << "Insufficient balance!\n";
        else {
            balance -= amt;
            cout << "Withdrawn: " << amt << endl;
        }
    }

    void show() {
        cout << "Account No: " << accNo << ", Name: " << name << ", Balance: " << balance << endl;
    }
};

map<int, Account> database;

int main() {
    int choice, accNo;
    string name;
    double amt;

    while (true) {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Show Account\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Account No: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Deposit: ";
            cin >> amt;
            database[accNo] = Account(name, accNo, amt);
        }
        else if (choice == 2) {
            cout << "Enter Account No: ";
            cin >> accNo;
            if (database.find(accNo) == database.end()) {
                cout << "Account not found!\n";
                continue;
            }
            cout << "Enter amount to deposit: ";
            cin >> amt;
            database[accNo].deposit(amt);
        }
        else if (choice == 3) {
            cout << "Enter Account No: ";
            cin >> accNo;
            if (database.find(accNo) == database.end()) {
                cout << "Account not found!\n";
                continue;
            }
            cout << "Enter amount to withdraw: ";
            cin >> amt;
            database[accNo].withdraw(amt);
        }
        else if (choice == 4) {
            cout << "Enter Account No: ";
            cin >> accNo;
            if (database.find(accNo) == database.end()) {
                cout << "Account not found!\n";
                continue;
            }
            database[accNo].show();
        }
        else if (choice == 5)
            break;
        else
            cout << "Invalid choice.\n";
    }
    return 0;
}
