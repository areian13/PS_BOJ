#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> r(9, 0), c(9, 0);
        for (int i = 0; i < n; i++)
        {
            int y, x;
            cin >> y >> x;
            r[y]++, c[x]++;
        }

        bool result = true;
        for (int i = 0; i < 9; i++)
            result &= (r[i] < 2);
        for (int j = 0; j < 9; j++)
            result &= (c[j] < 2);
        cout << (result ? "SAFE" : "NOT SAFE") << '\n';
    }
}