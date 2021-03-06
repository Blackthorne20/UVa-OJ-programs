//Evan Wood : Andy's First Dictionary : 10815 : Blackthorne20
//
//data structure required: set
//
//tricks of the trade: building words from characters,
//                     making words lowercase,
//                     using sets to alphabetize lists

#include <iostream>
#include <set>
#include <cctype>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line, word = "";
    set<string> dictionary;
    while (getline(cin, line))
    {
        //read the input one character at a time
        for (auto c : line)
        {
            //add each alphabetical character to word
            if (isalpha(c))
            {
                //make all letters lowercase
                c = tolower(c);
                word += c;
            }

            //once a non-alphabetical character is read,
            //store the word in the dictionary. Add only
            //if the word is one character or longer.
            else if (word.length() != 0)
            {
                dictionary.insert(word);

                //clear out word and start the process over
                word.clear();
            }
        }

        //if end of line is reached, store the word in the
        //dictionary before moving on to the next line
        if (word.length() != 0)
        {
            dictionary.insert(word);
            word.clear();
        }
    }
    for (auto s : dictionary)
    {
        cout << s << endl;
    }

    return 0;
}

