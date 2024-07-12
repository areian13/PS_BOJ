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

    array<int, 2> cnt = { 0,0 };
    for (int i = 0; i < n; i++)
        cnt[s[i] == '2']++;

    string result = (cnt[0] == cnt[1] ? "yee" : (cnt[0] > cnt[1] ? "e" : "2"));
    cout << result << '\n';
}