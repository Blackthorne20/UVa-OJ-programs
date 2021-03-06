//Evan Wood : The Decoder : 458 : Blackthorne20
//
//data structure required : string
//
//tricks of the trade : using ascii index manipulation to decode a message

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    while (getline(cin, text))
    {
        text.shrink_to_fit();

        //shift each input ascii value by minus seven and
        //print out the resulting character
        for (int i = 0; i < text.length(); i++)
        {
            cout << char(text[i] - 7);
        }
        cout << endl;
    }
    return 0;
}

