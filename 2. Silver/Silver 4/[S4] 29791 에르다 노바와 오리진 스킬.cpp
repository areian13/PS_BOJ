#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define TIME 1'000'000

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    array<int, 2> cnt = { n,m };
    array<array<bool, TIME + 1>, 2> isPushed = { false, };
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            int pushTime;
            cin >> pushTime;

            isPushed[i][pushTime] = true;
        }
    }

    array<int, 2> curCoolTime = { 0,0 };
    array<int, 2> skillCoolTime = { 100,360 };
    array<int, 2> result = { 0,0 };
    for (int i = 1; i <= TIME; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (isPushed[j][i])
            {
                if (curCoolTime[j] == 0)
                {
                    result[j]++;
                    curCoolTime[j] = skillCoolTime[j];
                }
            }
            curCoolTime[j] = max(curCoolTime[j] - 1, 0);
        }
    }
    cout << result[0] << ' ' << result[1] << '\n';
}