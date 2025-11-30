#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool Parallel(int a, int b, int c, int d)
{
    return a != c && b != d && abs(a - b) % 12 == 7 && abs(c - d) % 12 == 7;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    vector<int> result;
    for (int i = 0; i < n - 1; i++)
    {
        if (Parallel(a[i], b[i], a[i + 1], b[i + 1]))
            result.push_back(i);
    }

    if (result.empty())
        cout << "POLE" << '\n';
    else
    {
        for (int i : result)
            cout << i + 1 << '\n';
    }
}