#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Type2018(int n)
{
    array<int, 26> cnt = { 0, };
    while (n > 0)
    {
        int c = n % 10;
        if (c != 2 && c != 0 && c != 1 && c != 8)
            return 0;
        cnt[c]++;
        n /= 10;
    }

    if (!cnt[2] || !cnt[0] || !cnt[1] || !cnt[8])
        return 1;
    if (cnt[2] != cnt[0] || cnt[2] != cnt[1] || cnt[2] != cnt[8])
        return 2;
    return 8;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = Type2018(n);
    cout << result << '\n';
}