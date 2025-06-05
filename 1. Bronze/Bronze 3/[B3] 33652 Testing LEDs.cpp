#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        long long m, o;
        cin >> m >> o;

        if (!o)
            result = min(result, m);
    }

    if (result == LLONG_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}