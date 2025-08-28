#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string a, b;
    cin >> n >> a >> b;

    array<int, 26> cntA = { 0, }, cntB = { 0, };
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            r++;
        else
            cntA[a[i] - 'A']++, cntB[b[i] - 'A']++;
    }

    int s = 0;
    for (int i = 0; i < 26; i++)
        s += min(cntA[i], cntB[i]);
    cout << r << ' ' << s << '\n';
}