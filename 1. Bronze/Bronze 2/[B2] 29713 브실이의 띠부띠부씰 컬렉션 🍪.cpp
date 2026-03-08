#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string bs = "BRONZESILVER";
array<int, 26> need = { 0, };

int main()
{
    FastIO;

    for (char c : bs)
        need[c - 'A']++;

    int n;
    string s;
    cin >> n >> s;

    array<int, 26> cnt = { 0, };
    for (char c : s)
        cnt[c - 'A']++;

    int result = n;
    for (int i = 0; i < 26; i++)
    {
        if (need[i] == 0) continue;
        result = min(result, cnt[i] / need[i]);
    }
    cout << result << '\n';
}