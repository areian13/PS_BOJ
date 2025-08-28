#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinErase(string& s)
{
    array<int, 26> cnt = { 0, };
    for (char c : s)
        cnt[c - 'a']++;
    sort(cnt.begin(), cnt.end());
    return accumulate(cnt.begin(), cnt.end(), 0) - cnt[25] - cnt[24];
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = MinErase(s);
    cout << result << '\n';
}