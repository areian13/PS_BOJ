#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    vector<bool> rein(n, false);
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (a[i] > 0 && j < n)
        {
            rein[j++] = true, a[i]--;

            if (a[i] <= a[j])
                i = j;
        }
    }

    int result = accumulate(rein.begin(), rein.end(), 0);
    cout << result << '\n';
}