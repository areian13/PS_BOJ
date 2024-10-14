#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string v;
    cin >> v;

    array<int, 2> cnt = { 0,0 };
    for (char c : v)
        cnt[c == 'D' || c == 'P']++;

    string result = "";
    if (cnt[0] > (cnt[1] + 1) / 2)
        result += 'U';
    if (cnt[1] > 0)
        result += "DP";

    cout << result << '\n';
}