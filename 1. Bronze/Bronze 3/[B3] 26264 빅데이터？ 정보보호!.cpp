#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string BigOrSec(string& s)
{
    int n = s.size();

    array<int, 2> cnt = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        bool isS = (s[i] == 's');
        cnt[isS]++;
        i += 6 + isS;
    }

    if (cnt[0] > cnt[1])
        return "bigdata?";
    if (cnt[0] < cnt[1])
        return "security!";
    return "bigdata? security!";
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = BigOrSec(s);
    cout << result << '\n';
}