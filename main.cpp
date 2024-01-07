#include <iostream>
#include "functions.h"
using namespace std;

// block // + // block //

// 0. visual gluposti tam shte pishem?????
// 0.5 Brief description of services
// 1. log in?
// 2. input your assets and who you want them to go to
// 3. input personal information? - Personall account space? // this will help us find your corpse :D
// 4. Log out.
// 5. Congrats you've been scammed :)

// how do wills work
// There are two types of wills - 1. Bulgarian Handwritten Will (this is the one we'll be making) 2. Notarial Will
// - the text of the will must be kept secret, and also, there must be a date. Only the latest will is valid.
// requirements of the Bulgarian Legislation? - must be signed with full name and signature
// small end text - we recommend registering this will at the Notary office.

// change logo to codders


int main()
{
    int a;
    cin >> a;
    cout << a;
    registering();
    checkRequires();
    login();

}