#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsBomb(string& word, string& bomb)
{
    int n = word.size();
    int m = bomb.size();

    if (n < m)
        return false;

    for (int i = 0; i < m; i++)
    {
        if (word[n - m + i] != bomb[i])
            return false;
    }
    return true;
}

string ExplodedString(string& str, string& bomb)
{
    int m = bomb.size();

    string result = "";
    for (char c : str)
    {
        result += c;
        if (IsBomb(result, bomb))
            result.resize(result.size() - m);
    }

    return result;
}

int main()
{
    FastIO;

    string str, bomb;
    cin >> str >> bomb;

    string result = ExplodedString(str, bomb);
    if (result.empty())
        cout << "FRULA" << '\n';
    else
        cout << result << '\n';
}