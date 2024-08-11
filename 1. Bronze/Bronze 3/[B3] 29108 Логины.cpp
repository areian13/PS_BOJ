#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsCorrect(string& s)
{
    if (s.size() <= 2 || s[0] != 'i' || s[1] != 'o')
        return false;

    for (int i = 2; i < s.size(); i++)
    {
        if (!('0' <= s[i] && s[i] <= '9'))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = (IsCorrect(s) ? "Correct" : "Incorrect");
    cout << result << '\n';
}