#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int f(int x)
{
    return x % 10;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> result;
    for (int x = 1; x <= n; x++)
    {
        if (f(x) != f(k) && f(x) != f(k * 2))
            result.push_back(x);
    }

    int m = result.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++)
        cout << result[i] << ' ';
    cout << '\n';
}