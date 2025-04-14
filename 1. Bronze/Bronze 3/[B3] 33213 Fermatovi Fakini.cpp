#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 2> cnt = { 0,0 };
    array<bool, MAX> use = { false, };
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cnt[a % 2]++;
        use[a] = true;
    }

    int result = 0;
    for (int i = 1; i < MAX; i++)
    {
        if (cnt[i % 2] > cnt[(i + 1) % 2] && !use[i])
        {
            result = i;
            break;
        }
    }
    cout << result << '\n';
}