#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 2> cnt = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cnt[a % 2]++;
    }

    long long result = (long long)cnt[0] * cnt[1];
    cout << result << '\n';
}