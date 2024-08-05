#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, r;
    cin >> n >> r;

    array<int, 2> cnt = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        if (r == p)
            continue;

        cnt[r > p]++;
    }

    int result = (cnt[0] == cnt[1] ? 0 : (cnt[0] < cnt[1] ? 1 : 2));
    cout << result << '\n';
}
