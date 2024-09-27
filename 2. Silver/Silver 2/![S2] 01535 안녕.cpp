#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 20'000

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];

    vector<int> j(n);
    for (int i = 0; i < n; i++)
        cin >> j[i];

    vector<vector<int>> dp(n, vector<int>(MAX + 1, 0));
    for (int i = 0; i < n; i++)
    {
    }
}