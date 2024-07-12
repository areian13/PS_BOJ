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
        if (word[n - i - 1] != bomb[m - i - 1])
            return false;
    }
    return true;
}

string ExplodedString(string& str, string& bomb)
{
    int n = bomb.size();
    string result = "";
    for (char c : str)
    {
        result += c;
        if (IsBomb(result, bomb))
            result.erase(result.size() - n, result.size());
    }

    if (result == "")
        result = "FRULA";
    return result;
}

int main()
{
    FastIO;

    string str, bomb;
    cin >> str >> bomb;

    string result = ExplodedString(str, bomb);
    cout << result << '\n';
}