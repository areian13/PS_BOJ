#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsSign(char c)
{
    return c == '!' || c == '?' || c == ',' || c == '.';
}
bool IsSign(string str)
{
    if (str.size() != 1)
        return false;
    return IsSign(str[0]);
}

void Change(vector<string>& words)
{
    while (true)
    {
        bool isChanged = false;
        int n = words.size();

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && words[i] == "of" && words[i + 1] == "Korea" && !IsSign(words[i - 1]))
            {
                isChanged = true;

                if ('a' <= words[i - 1][0] && words[i - 1][0] <= 'z')
                    words[i - 1][0] -= 32;

                words.erase(words.begin() + i + 1);
                words.erase(words.begin() + i);
                words[i - 1] = "K-" + words[i - 1];
                break;
            }
        }
        if (!isChanged)
            break;
    }

    while (true)
    {
        bool isChanged = false;
        int n = words.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (words[i] == "Korea" && !IsSign(words[i + 1]))
            {
                isChanged = true;

                if ('a' <= words[i + 1][0] && words[i + 1][0] <= 'z')
                    words[i + 1][0] -= 32;

                words[i + 1] = "K-" + words[i + 1];
                words.erase(words.begin() + i);
                break;
            }
        }
        if (!isChanged)
            break;
    }
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    cin.ignore();
    while (tc--)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> words;
        string word;
        while (ss >> word)
        {
            if (IsSign(word.back()))
            {
                words.push_back(word.substr(0, word.size() - 1));
                words.push_back(word.substr(word.size() - 1, 1));
            }
            else
                words.push_back(word);
        }

        Change(words);

        for (int i = 0; i < words.size(); i++)
        {
            cout << words[i];
            if (IsSign(words[i + 1]))
            {
                cout << words[i + 1] << ' ';
                i++;
            }
            else
                cout << ' ';
        }
        cout << '\n';
    }
}