#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> e(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
        sum += e[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (sum - e[i] == e[i])
            swap(e[i], e[n - 1]);
        cout << e[i] << ' ';
    }
    cout << '\n';
}