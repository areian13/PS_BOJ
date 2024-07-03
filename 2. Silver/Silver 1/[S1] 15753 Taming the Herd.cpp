#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanEscape(vector<int>& a, array<int, 2>& result)
{
    int n = a.size();

    vector<int> mustEscape(n, false), mayEscape(n, true);
    mustEscape[0] = true;

    int lastEscape = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            continue;

        if (a[i] > i - lastEscape || !mayEscape[i - a[i]])
            return false;

        lastEscape = i - a[i];
        mustEscape[lastEscape] = true;

        for (int j = lastEscape + 1; j <= i; j++)
            mayEscape[j] = false;
    }

    for (int i = 0; i < n; i++)
    {
        result[0] += mustEscape[i];
        result[1] += mayEscape[i];
    }

    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    array<int, 2> result = { 0,0 };
    if (!CanEscape(a, result))
        cout << -1 << '\n';
    else
        cout << result[0] << ' ' << result[1] << '\n';
}