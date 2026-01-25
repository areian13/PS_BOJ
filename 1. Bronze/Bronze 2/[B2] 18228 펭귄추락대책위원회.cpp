#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    int p = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == -1)
            p = i;
    }

    int l = 0;
    for (int i = 0; i < p; i++)
    {
        if (a[i] < a[l])
            l = i;
    }
    int r = p + 1;
    for (int i = p + 1; i < n; i++)
    {
        if (a[i] < a[r])
            r = i;
    }

    int result = a[l] + a[r];
    cout << result << '\n';
}