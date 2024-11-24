#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 4> charges;
    charges[0] = 0;
    for (int i = 1; i <= 3; i++)
        cin >> charges[i];

    array<int, 101> cnt = { 0, };
    for (int i = 0; i < 3; i++)
    {
        int s, e;
        cin >> s >> e;

        for (int t = s; t < e; t++)
            cnt[t]++;
    }

    int result = 0;
    for (int i = 1; i <= 100; i++)
        result += charges[cnt[i]] * cnt[i];
    cout << result << '\n';
}