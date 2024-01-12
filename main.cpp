#include <iostream>
#include "functions.h"
#include <conio.h>
using namespace std;

// 3. input personal information? - Personall account space? // this will help us find your corpse

// how do wills work
// There are two types of wills - 1. Bulgarian Handwritten Will (this is the one we'll be making) 2. Notarial Will
// - the text of the will must be kept secret, and also, there must be a date. Only the latest will is valid.
// requirements of the Bulgarian Legislation? - must be signed with full name and signature
// small end text - w
//e recommend registering this will at the Notary office.


int main()
{
    registering();
    checkRequires();
    login();
    getInfo();

    //cout << "In the following, please put the contents of your will and their intended recipent/s. " << endl;
    createWill();
    printWill();
    logout();
}