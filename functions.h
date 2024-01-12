#include <iostream>
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

    string beneficiaries[100];
    string executor;
    string uniqueSignature;
}

struct NODE 
{
    string item;
    string recipent;
    NODE* next;
}
void prependNode(NODE *&head, string item, string recipent)
{
    NODE* newNode = new NODE;
    newNode->next = head;
    newNode->item = item;
    newNode->recipent = recipent;
    head = newNode;
}
void printList(NODE *head)
{
    NODE* temp = head;
    while(temp != NULL)
    {
        cout << "I bequest " << temp->item << " to beneficiary " << temp->recipient << endl;
        temp = temp->next;
    }
}

Register registerData;
Register loginData;
Person user;
int numberBeneficiaries;

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
    while (true)
    {
        if (registerData.username.find("@codingburgas.bg") != string::npos && containsDigit(registerData.password))
        {
            cout << "Registered successful";
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

                //Makes a NODE list for the user.
                NODE* head = new NODE;

                break;
            }
        }
        else
        {
            cout << "There is no username like this! Try again." << endl;
        }
    }
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
    cin >> user.data;
    cout << endl;

    cout << "Enter the number of beneficiaries: "
    cin >> numberBeneficiaries;
	cout << "\nEnter beneficiary: ";
    for (int i = 0; i < numberBeneficiaries; i++)
    {	
        cin >> user.beneficiaries[i];
    }
    cout << endl;

    cout << "Enter the executor of your will. ";
    cin >> user.executor;
    cout << endl;

    cout << "Lastly, enter your signature. This will be used to sign your will. ";
    cin >> user.uniqueSignature;
    cout << endl;
}

void createWill() 
{
    string item;
    cout << "Please enter your asset/s or item/s: ";
    getline(cin, item);

    string recipient;
    cout << "The intended recipent: ";
    getline(cin, recipient);

    cout << "I bequeath " << item << " to " << recipient << ". Is this correct? y/n\n";

    string answer;
    getline(cin, answer);
    if(string == "yes" || string == "y" || string == "Yes")
    {
        prependNode(head, item, recipent);
		cout << "\nAsset has been added. Continue adding assets? y/n";
        cin >> answer;
		if (string == "yes" || string == "y" || string == "Yes")
        {
            cout << endl;
            createWill();
        }
    }else{
        cout << "\nAsset has not been added. Continue adding assets? y/n";
		if (string == "yes" || string == "y" || string == "Yes")
		{
			cout << endl;
			createWill();
		}
    }
    
  
void printWill()
{
    // the below code may or may not work
    cout << "\033[2J\033[H"; // ANSI escape codes to clear the console

    cout << "Your will is complete. Here it is: " << endl;
    

    cout << "      Name: " << user.name << endl;

    cout << "      Surname: " << user.surname << endl;

    cout << "      Date:" << user.date << endl;

    cout << "      Beneficiaries: ";
    for (int i = 0; i < numberBeneficiaries; i++)
    {
        cout << user.beneficiaries[i] << " ";
    }
    cout << endl;
    cout << "      Executor: " << user.executor << endl;


    cout << "This is my last will and testament. " << endl
    printList(head);

    cout << "Signed, " << user.uniqueSignature;


}

void logout()
{
    cout << "Press any key to logout...\n";
    _getch();  // Press _getch() to logout

    cout << "Logout successful.\n";
}