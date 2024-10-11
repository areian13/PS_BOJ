#include <iostream>
#include <string>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountDeleteChar(string& a, string& b)
{
    array<int, 26> cntA = { 0, };
    for (char c : a)
        cntA[c - 'a']++;

    array<int, 26> cntB = { 0, };
    for (char c : b)
        cntB[c - 'a']++;

    int result = 0;
    for (int i = 0; i < 26; i++)
        result += abs(cntA[i] - cntB[i]);
    return result;
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int result = CountDeleteChar(a, b);
    cout << result << '\n';
}