#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
    cout << "Would you like to login or register?" << endl;
    string choice = "null"; 
    while ((choice != "login") && (choice != "register"))
    {
        cin >> choice;
        tolower(choice[0]);
    }
    
    
    if (choice == "register")
    {
        ofstream out("usernames.txt", ios::app); 
        
        cout << "Please enter your username" << endl;
        string username;
        cin >> username;
        cout << "Please enter your password" << endl;
        string password;
        cin >> password;

        out << username << " " << password << "\n";

        cout << "Registration Successful!" << endl;
        
        out.close();
    }

    if (choice == "login")
    {
        cout << "Please enter your username" << endl;
        string username;
        cin >> username;
        cout << "Please enter your password" << endl;
        string password;
        cin >> password;

        ifstream inputFile("usernames.txt");
        string line;
        while (getline(inputFile, line))
        {
            istringstream iss(line);

            string first;
            iss >> first;
            string second;
            iss >> second;

            if (first == username && second == password)
            {
                cout << "Valid credentials found." << endl;
            }
        }

        inputFile.close();
    }
    

    return 0;
}