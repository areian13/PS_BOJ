#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    array<int, 26> cntA = { 0, };
    for (char c : a)
        cntA[c - 'a']++;

    array<int, 26> cntB = { 0, };
    for (char c : b)
        cntB[c - 'a']++;

    string result = "";
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < max(cntA[i], cntB[i]); j++)
            result += i + 'a';
    }
    cout << result << '\n';
}