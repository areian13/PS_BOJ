#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string word;
    cin >> word;

    int n = word.size();
    int result = 0;
    cin.ignore();
    while (true)
    {
        string text;
        getline(cin, text);

        if (cin.eof())
            break;

        int k = text.size();
        for (int i = 0; i < k; i++)
            result += (word == text.substr(i, n));
    }
    cout << result << '\n';
}