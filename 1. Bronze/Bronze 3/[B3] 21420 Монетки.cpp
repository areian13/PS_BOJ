#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 2> cnt = { 0,0 };

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        bool a;
        cin >> a;

        cnt[a]++;
    }

    int result = min(cnt[0], cnt[1]);
    cout << result << '\n';
}