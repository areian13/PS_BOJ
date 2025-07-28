#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    array<int, 26> cnt = { 0, };
    for (char c : s)
        cnt[c - 'a']++;

    int cntH = 0;
    for (int i = 0; i < 26; i++)
        cntH += cnt[i] & 1;

    int result = max(cntH - 1, 0);
    cout << result << '\n';
}