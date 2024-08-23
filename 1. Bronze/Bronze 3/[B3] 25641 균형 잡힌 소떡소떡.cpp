#include <iostream>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Balanced(string s)
{
    int n = s.size();

    array<int, 2> cnt = { 0,0 };
    for (int i = 0; i < n; i++)
        cnt[s[i] == 't']++;

    reverse(s.begin(), s.end());
    while (cnt[0] != cnt[1])
    {
        cnt[s.back() == 't']--;
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = Balanced(s);
    cout << result << '\n';
}
