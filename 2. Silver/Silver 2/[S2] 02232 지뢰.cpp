#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPowerful(int i, vector<int>& p)
{
    int n = p.size();

    if (i == 0)
        return p[i] >= p[i + 1];
    if (i == n - 1)
        return p[i] >= p[i - 1];
    return (p[i - 1] <= p[i] && p[i] >= p[i + 1]);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    for (int i = 0; i < n; i++)
    {
        if (IsPowerful(i, p))
            cout << i + 1 << '\n';
    }
}