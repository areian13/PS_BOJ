#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> use(m);
    for (int i = 0; i < m; i++)
        cin >> use[i];

    int e = pow(10, n);
    int result = 0;
    for (int i = 0; i < e; i++)
    {
        int t = i;
        vector<bool> used(10, false);
        for (int j = 0; j < n; j++)
        {
            used[t % 10] = true;
            t /= 10;
        }

        bool flag = true;
        for (int j : use)
            flag &= used[j];
        result += flag;
    }
    cout << result << '\n';
}