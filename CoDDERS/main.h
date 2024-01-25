#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

struct Register
{
    string username;
    string password;
};

struct Person
{
    string name;
    string surname;
    string date;
    string executor;
    string uniqueSignature;
};

struct NODE
{
    string item;
    string recipent;
    NODE* next;
};


Register registerData;
Register loginData;
Person user;
string beneficiaries[100];
int numberBeneficiaries;
struct NODE* head = NULL;

void prependNode(NODE*& head, string item, string recipent)
{
    NODE* newNode = new NODE;
    newNode->next = head;
    newNode->item = item;
    newNode->recipent = recipent;
    head = newNode;
}

void printList(NODE* head)
{
    NODE* temp = head;
    while (temp != NULL)
    {
        cout << "I bequest " << temp->item << " to beneficiary " << temp->recipent << endl;
        temp = temp->next;
    }
}


bool containsDigit(string str)
{
    for (char c : str)
    {
        if (isdigit(c))
        {
            return true;
        }
    }
    return false;
}

void registering()
{
    cout << "Welcome to the Digital Will!" << endl;

    cout << "Register yourself." << endl;
    cout << endl;

    cout << "Your username must contain \"codingburgas.bg\".Enter your username: ";
    getline(cin, registerData.username);
    cout << endl;

    cout << "Your password must contain a number. Enter your password: ";
    getline(cin, registerData.password);
    cout << endl;
}

void checkRequires()
{
    cout << "\033[2J\033[H"; // ANSI escape codes to clear the console
    while (true)
    {
        if (registerData.username.find("@codingburgas.bg") != string::npos && containsDigit(registerData.password))
        {
            cout << "Registered successful" << endl;
            cout << "Now, log in.";
            cout << endl;
            break;
        }

        else
        {
            cout << "Your data doesn't match our requires. Try again registering." << endl;
            cout << endl;
            cout << "Your username must contain \"codingburgas.bg\".Enter your username : ";
            getline(cin, registerData.username);
            cout << endl;
            cout << "Your password must contain a number. Enter your password: ";
            getline(cin, registerData.password);
        }
    }
}

void login()
{
    while (true)
    {
        cout << "Enter your username: ";
        getline(cin, loginData.username);
        cout << endl;
        cout << "Enter your password: ";
        getline(cin, loginData.password);

        cout << "Checking if there is an email like this..." << endl;
        cout << endl;

        if (loginData.username == registerData.username)
        {
            if (loginData.password == registerData.password)
            {
                cout << "Welcome " << loginData.username << "! You can continue working." << endl;
                cout << endl;
                break;
            }
        }
        else
        {
            cout << "There is no username like this! Try again." << endl;
        }
    }
}

void create(string name, string username, string date, string beneficiaries[], string executor, string uniqueSignature)
{
    // file pointer 
    fstream fout;

    // opens an existing csv file or creates a new file. 
    string filename = user.name + user.surname;
    fout.open("userData/" + filename +".csv", ios::out | ios::app);

    fout << "Basic data: \n Name: " << name << "\n Username: " << username << "\n Date: " << date << "\n Beneficiaries: ";
    for (int i = 0; i < numberBeneficiaries; i++)
    {
        fout << beneficiaries[i] << ", ";
    }
    fout << "\n Executor: " << executor << "\n Signed: " << uniqueSignature << "\n";
}

void getInfo()
{
    cout << "The first part of making a CV is writing your personal information. Please answer the questions below." << endl;

    cout << "Enter name: ";
    getline(cin, user.name);
    cout << endl;

    cout << "Enter surname: ";
    getline(cin, user.surname);
    cout << endl;

    cout << "Enter the current date: ";
    cin >> user.date;
    cout << endl;

    cout << "Enter the number of beneficiaries: ";
    cin >> numberBeneficiaries;

    cout << "\nEnter beneficiary: ";
    for (int i = 0; i < numberBeneficiaries; i++)
    {
        cin >> beneficiaries[i];
    }
    cout << endl;

    cout << "Enter the executor of your will: ";
    cin >> user.executor;
    cout << endl;

    cout << "Lastly, enter your signature. This will be used to sign your will: ";
    cin >> user.uniqueSignature;
    cout << endl;

    create(user.name, user.surname, user.date, beneficiaries, user.executor, user.uniqueSignature);
}

void createWill()
{
    string item;

    while (true)
    {
        ////
        cout << "Please enter your asset/s or item/s: ";
        cin >> item;
        cout << endl;

        string recipient;
        while (true)
        {
            cout << "The intended recipient: ";
            cin >> recipient;

            // Check if the recipient is in the array beneficiaries
            auto it = find(begin(beneficiaries), end(beneficiaries), recipient);

            if (it != end(beneficiaries))
            {
                break; // Exit the loop if recipient is found in the array beneficiaries
            }
            else
            {
                cout << "Recipient not found in the listed beneficiaries. Try again." << endl;
            }
        }
        cout << endl;
        prependNode(head, item, recipient);
        cout << "Thus added: I bequeath " << item << " to " << recipient << "." << endl;
        ///
        cout << "MORE assets?! y/n : ";
        cin >> item;
        if (item == "n" || item == "No" || item == "no")
        {
            break;
        }
    }


}


void printWill()
{
    cout << "\033[2J\033[H"; // ANSI escape codes to clear the console

    cout << "Your will is complete. Here it is: " << endl;
    cout << "      Name: " << user.name << endl;
    cout << "      Surname: " << user.surname << endl;
    cout << "      Date: " << user.date << endl;
    cout << "      Beneficiaries: ";
    for (int i = 0; i < numberBeneficiaries; i++)
    {
        cout << beneficiaries[i] << "; ";
    }
    cout << endl;
    cout << "      Executor: " << user.executor << endl;

    cout << "This is my last will and testament. " << endl;
    cout << endl;
    printList(head);
    cout << endl;

    cout << "Signed, " << user.uniqueSignature << endl;


}

void logout()
{
    cout << "Press any key to exit..." << endl;
    _getch(); // Waits for a key press
    exit(0); // Exits the program
}