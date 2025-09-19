#include <iostream>
#include <string>
using namespace std;

int check(string category[], int size, string answer, int id[])
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (category[i] == answer)
        {
            id[count++] = i;
        }
    }
    return count;
}

string recommendation(int id[], int count, string book_name[])
{
    if (count == 0)
    {
        return "Sorry, we couldn't find your genre in our list.";
    }
    else
    {
        string result = "We found these books for you, hope to enjoy:\n";
        for (int i = 0; i < count; i++)
        {
            result += "- " + book_name[id[i]] + "\n";
        }
        return result;
    }
}

int main()
{
    string book_name[] = {"The Midnight Library", "I Fell in Love with Hope", "They Both Die at the End", "Wuthering Heights", "the notebook"};
    string category[] = {"philosophical", "romance", "friendship", "gothic", "romance"};
    int size = sizeof(category) / sizeof(category[0]);
    int ID[5] = {0};

    string genre;
    cout << "What is your favorite genre in books? " << endl;
    cin >> genre;

    int found = check(category, size, genre, ID);
    cout << recommendation(ID, found, book_name);

    return 0;
}
