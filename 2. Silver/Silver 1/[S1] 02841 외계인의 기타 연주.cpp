#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, p;
    cin >> n >> p;

    vector<vector<int>> press(n + 1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int l, k;
        cin >> l >> k;

        while (!press[l].empty() && press[l].back() > k)
        {
            press[l].pop_back();
            result++;
        }

        if (press[l].empty() || press[l].back() < k)
        {
            press[l].push_back(k);
            result++;
        }
    }

    cout << result << '\n';
}