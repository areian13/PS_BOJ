#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> cnt(MAX + 1, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        int result = 0;
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                result += cnt[j];
                if (j * j != a[i])
                    result += cnt[a[i] / j];
            }
        }
        cout << result - 1 << '\n';
    }
}