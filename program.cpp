/*
Login and Registration System
The login And Registration System project in C++ involves mainly the user registration process. 
User Credentials like usernames and passwords are asked from the user. 
If the registration of the user is successful then with
the given credentials a file will be created of a particular user in the database
*/

#include <iostream>
#include <fstream>  // For file handling
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Open file in append mode to add new user credentials
    ofstream file("database.txt", ios::app);
    
    if (file.is_open()) {
        file << username << " " << password << endl;  // Store credentials
        cout << "Registration successful!\n";
    } else {
        cout << "Error opening file!\n";
    }

    file.close();  // Close the file
}

// Function to login a user
bool loginUser() {
    string username, password, fileUser, filePass;
    
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("database.txt");  // Open file in read mode
    
    if (file.is_open()) {
        while (file >> fileUser >> filePass) {  // Read username & password from file
            if (fileUser == username && filePass == password) {
                cout << "Login successful! Welcome, " << username << "!\n";
                file.close();
                return true;  // Successful login
            }
        }
        file.close();
        cout << "Invalid username or password. Try again!\n";
        return false;  // Failed login
    } else {
        cout << "Error opening file!\n";
        return false;
    }
}

// Main function with menu
int main()
{
    int choice;

    while (true) 
    {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;  // Exit program
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }
}