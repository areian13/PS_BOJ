#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    array<int, 26> cnt = { 0, };
    for (char c : s)
        cnt[c - 'A']++;

    for (char c : "JOI")
        cout << string(cnt[c - 'A'], c);
    cout << '\n';
}