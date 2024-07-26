#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void BT(int k, int n, vector<int>& result)
{
    int m = result.size();

    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = k == 0 ? 0 : result[k - 1]; i < n; i++)
    {
        result[k] = i + 1;
        BT(k + 1, n, result);
    }
}

void PrintNM(int n, int m)
{
    vector<int> result(m);
    BT(0, n, result);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    PrintNM(n, m);
}