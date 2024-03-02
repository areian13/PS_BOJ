#include <iostream>
#include <array>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 3> s;
    for (int i = 0; i < 3; i++)
        cin >> s[i];

    int n = s[0] + s[1] + s[2] + 1;
    vector<int> cnt(n);
    for (int i = 1; i <= s[0]; i++)
    {
        for (int j = 1; j <= s[1]; j++)
        {
            for (int k = 1; k <= s[2]; k++)
            {
                int sum = i + j + k;
                cnt[sum]++;
            }
        }
    }

    int result = 0;
    int maxCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] > maxCnt)
        {
            maxCnt = cnt[i];
            result = i;
        }
    }

    cout << result << '\n';
}