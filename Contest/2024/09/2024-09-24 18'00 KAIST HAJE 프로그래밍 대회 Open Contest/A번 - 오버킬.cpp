#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, d, p;
    cin >> n >> d >> p;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
            continue;

        while (a[i] > 0)
        {
            result++;
            a[i] -= d;
        }

        if (i != n - 1)
            a[i + 1] -= -a[i] * p / 100;
    }
    cout << result << '\n';
}