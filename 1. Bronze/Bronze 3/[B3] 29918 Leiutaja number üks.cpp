#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 6> cnt;
    int maxIndex = 0;
    for (int i = 0; i < 6; i++)
    {
        int n, m;
        cin >> n >> m;

        cnt[i] = n + m * 10;
        if (cnt[maxIndex] <= cnt[i])
            maxIndex = i;
    }

    int result = cnt[maxIndex] - cnt[0] + (maxIndex != 0);
    cout << result << '\n';
}