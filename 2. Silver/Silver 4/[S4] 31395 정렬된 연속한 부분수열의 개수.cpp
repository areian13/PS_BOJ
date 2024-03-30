#include <iostream>
#include <vector>

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

    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        long long cnt = 1;
        while (i < n - 1 && a[i] < a[i + 1])
        {
            i++;
            cnt++;
        }
        result += cnt * (cnt + 1) / 2;
    }
    cout << result << '\n';
}