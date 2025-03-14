#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "#")
            break;

        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            if (word.size() >= 3)
                reverse(word.begin() + 1, word.end() - 1);
            cout << word << ' ';
        }
        cout << '\n';
    }
}