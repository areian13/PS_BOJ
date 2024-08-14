#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 10> cnt = { 0, };
    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;

        cnt[n]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (cnt[i] % 2 == 0)
            continue;

        cout << i << '\n';
    }
}