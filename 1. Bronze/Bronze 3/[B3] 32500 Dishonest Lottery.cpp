#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 50

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, MAX + 1> cnt = { 0, };
    for (int i = 0; i < n * 50; i++)
    {
        int a;
        cin >> a;
        
        cnt[a]++;
    }

    bool hasOverN2 = false;
    for (int i = 1; i <= MAX; i++)
    {
        if (cnt[i] > n * 2)
        {
            cout << i << ' ';
            hasOverN2 = true;
        }
    }

    if (!hasOverN2)
        cout << -1 << '\n';
    else
        cout << '\n';
}