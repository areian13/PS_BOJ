#include <iostream>
#include <array>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsFixFree(string& a, string& b, string& c)
{
    int n = a.size();
    int m = b.size();
    int k = c.size();

    if (n <= m && a == b.substr(0, n))
        return false;
    if (m >= k && b.substr(m - k) == c)
        return false;
    return true;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        array<string, 3> words;
        for (int i = 0; i < 3; i++)
            cin >> words[i];

        bool result = true;
        sort(words.begin(), words.end());
        do
        {
            result &= IsFixFree(words[0], words[1], words[2]);
        } while (next_permutation(words.begin(), words.end()));

        if (result == true)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}