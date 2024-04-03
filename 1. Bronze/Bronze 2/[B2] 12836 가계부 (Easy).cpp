#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<long long> day(n + 1, 0);
    while (m--)
    {
        int type, p, q;
        cin >> type >> p >> q;

        if (type == 1)
            day[p] += q;
        else if (type == 2)
        {
            long long result = 0;
            for (int i = p; i <= q; i++)
                result += day[i];
            cout << result << '\n';
        }
    }
}