#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int k = m % n;
        m /= n;
        k += m;
        m *= (n - 1);
        result.push_back(k);
    }

    for (int k : result)
        cout << k << ' ';
    cout << '\n' << m << '\n';
}