//Evan Wood : WERTYU : 10082 : Blackthorne20
//
//data structure required : vector, 
//
//tricks of the trade : using ascii indexing to decode a message

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    string text;
    while (getline(cin, text))
    {
        string qwerty = "QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.`1234567890- ";
        string  werty = "WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./1234567890-= ";
        vector<char> Table(128, 0);
        for (int i = 0; i < qwerty.size(); i++)
        {
            Table[werty[i]] = qwerty[i];
        }

        //go through each input character, print its translated character
        for (unsigned int i = 0; i < text.length(); i++)
        {
            cout << Table[text[i]];
        }
        cout << endl;
    }

    return 0;
}

