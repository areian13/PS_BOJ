#include <iostream>
#include <vector>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            int d = a[i] - a[j];
            if (cnt.count(d) == 0)
                continue;

            int r = (d == a[i]) + (d == a[j]);
            if (cnt[d] == r)
                continue;

            result++;
            break;
        }
    }
    cout << result << '\n';
}