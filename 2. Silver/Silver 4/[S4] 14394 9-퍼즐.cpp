#include <iostream>
#include <string>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    array<int, 26> aCnt = { 0, }, bCnt = { 0, };
    for (int i = 0; i < 10; i++)
    {
        if (a[i] != '*') aCnt[a[i] - 'A']++;
        if (b[i] != '*') bCnt[b[i] - 'A']++;
    }

    int result = 0;
    for (int i = 0; i < 26; i++)
        result += abs(aCnt[i] - bCnt[i]);
    result /= 2;
    cout << result << '\n';
}