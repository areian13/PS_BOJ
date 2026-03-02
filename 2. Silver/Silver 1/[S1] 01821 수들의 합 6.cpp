#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 10;
vector<vector<int>> pascal(MAX, vector<int>(MAX, 0));

int Pascal(vector<int>& a)
{
    int n = a.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += pascal[n - 1][i] * a[i];
    return sum;
}

int main()
{
    FastIO;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0) pascal[i][j] = 1;
            else pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
        }
    }

    int n, f;
    cin >> n >> f;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    do
    {
        int pas = Pascal(a);
        if (pas == f)
            break;
    } while (next_permutation(a.begin(), a.end()));

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}