#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, bool> dictionary;

    string words[] = {"apple", "banana",
                      "cherry", "dog", "elephant", "frog",
                      "grape", "hat", "ice-cream", "jacket"};
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); ++i)
    {
        dictionary.insert({words[i], true});
    }

    cout << "Words in the dictionary:" << endl;

    unordered_map<string, bool>::iterator it;
    for (it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        cout << it->first << endl;
    }

    string searchWord;
    char choice;
    do
    {
        cout << "\nEnter a word to search in the dictionary: ";
        cin >> searchWord;

        it = dictionary.find(searchWord);
        if (it != dictionary.end())
        {
            cout << searchWord << " is in the dictionary." << endl;
        }
        else
        {
            cout << searchWord << " is NOT in the dictionary." << endl;
        }

        cout << "Do you want to search for another word? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
