#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsEvenOrOddStr(array<int, 26>& cnt, int eo)
{
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 0)
            continue;
        if (cnt[i] % 2 != eo)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    string str;
    cin >> str;

    array<int, 26> cnt = { 0, };
    for (char c : str)
        cnt[c - 'a']++;

    string result = "0/1";
    for (int i = 0; i < 2; i++)
    {
        if (IsEvenOrOddStr(cnt, i))
        {
            result = to_string(i);
            break;
        }
    }
    cout << result << '\n';
}