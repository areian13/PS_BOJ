#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        result += a;
    }
    for (int j = 0; j < m; j++)
    {
        int b;
        cin >> b;
        result += b;
    }
    cout << result << '\n';
}