#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, MAX + 1> cnt = { 0, };
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cnt[a]++;
    }

    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
            cout << i << '\n';
    }
}