#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHavingSameChar(string& s)
{
    array<bool, 26> isExisted = { false, };
    for (char c : s)
    {
        if (isExisted[c - 'a'])
            return true;
        isExisted[c - 'a'] = true;
    }
    return false;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    bool result = !IsHavingSameChar(s);
    cout << result << '\n';
}