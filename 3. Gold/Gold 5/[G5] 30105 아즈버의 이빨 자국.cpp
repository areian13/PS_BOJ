#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsAzber(int k, vector<int>& x, unordered_map<int, bool>& mark)
{
    for (int p : x)
    {
        if (!mark[p - k] && !mark[p + k])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> x(n);
    unordered_map<int, bool> mark;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        mark[x[i]] = true;
    }

    vector<int> result;
    for (int i = 1; i < n; i++)
    {
        int k = x[i] - x[0];

        if (IsAzber(k, x, mark))
            result.push_back(k);
    }

    cout << result.size() << '\n';
    for (int k : result)
        cout << k << '\n';
}