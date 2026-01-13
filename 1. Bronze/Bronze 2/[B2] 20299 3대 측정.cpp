#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k, l;
    cin >> n >> k >> l;

    vector<vector<int>> result;
    for (int i = 0; i < n; i++)
    {
        vector<int> x(3);
        int sum = 0;
        bool pass = true;
        for (int j = 0; j < 3; j++)
        {
            cin >> x[j];
            sum += x[j];
            pass &= (x[j] >= l);
        }

        if (pass && sum >= k)
            result.push_back(x);
    }

    cout << result.size() << '\n';
    for (auto& x : result)
        cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ';
    cout << '\n';
}