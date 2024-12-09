#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int AnagramDist(string& a, string& b)
{
    array<int, 26> cntA = { 0, }, cntB = { 0, };
    for (char c : a)
        cntA[c - 'a']++;
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

    int TC;
    cin >> TC;
    cin.ignore();

    for (int tc = 1; tc <= TC; tc++)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);

        int result = AnagramDist(a, b);
        printf("Case #%d: %d\n", tc, result);
    }
}