#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> f(n);
    int sum = 0, unsum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        sum += f[i];
    }
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        unsum += f[i] * !m;
    }
    cout << sum << '\n' << unsum << '\n';
}