#include <iostream>
#include <string>
#include <array>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountHIARC(string& s)
{
    array<int, 26> cnt = { 0, };
    for (char c : s)
        cnt[c - 'A']++;

    int result = INT_MAX;
    for (char c : (string)"HIARC")
        result = min(result, cnt[c - 'A']);
    return result;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    int result = CountHIARC(s);
    cout << result << '\n';
}