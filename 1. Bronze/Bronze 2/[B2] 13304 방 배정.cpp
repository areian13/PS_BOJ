#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> cnt(5, 0);
    for (int i = 0; i < n; i++)
    {
        int s, y;
        cin >> s >> y;

        y = (y - 1) / 2;
        if (y == 0)
            cnt[0]++;
        else
            cnt[y * 2 - s]++;
    }

    int result = 0;
    for (int i = 0; i < 5; i++)
        result += (cnt[i] == 0 ? 0 : (cnt[i] - 1) / k + 1);
    cout << result << '\n';
}