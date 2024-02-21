#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 1'001> cnt = { 0, };

    int n, p;
    cin >> n >> p;

    int result = 0;
    int num = n;
    while (true)
    {
        cnt[num]++;
        num *= n;
        num %= p;

        if (cnt[num] == 1)
            result++;
        else if (cnt[num] == 2)
            break;
    }
    cout << result << '\n';
}