#include <iostream>
#include <vector>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> BeautifulRibbon(vector<int>& x, vector<int>& l, vector<char>& c)
{
    int n = x.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(x[i] - x[j]) <= l[i] + l[j] && c[i] != c[j])
                return { i,j };
        }
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];

    vector<char> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    array<int, 2> result = BeautifulRibbon(x, l, c);
    if (result == array<int, 2>{ -1, -1 })
        cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        cout << result[0] + 1 << ' ' << result[1] + 1 << '\n';
    }
}