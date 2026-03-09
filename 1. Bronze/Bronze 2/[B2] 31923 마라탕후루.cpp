#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> SBSM(int p, int q, vector<int>& a, vector<int>& b)
{
    int n = a.size();

    vector<int> result(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[i] != b[i])
        {
            result[i]++, sum++;
            a[i] += p, b[i] += q;

            if (sum > 10'000)
                return {};
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, p, q;
    cin >> n >> p >> q;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> result = SBSM(p, q, a, b);
    if (result.empty())
        cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}