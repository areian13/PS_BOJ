#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        sum = max(sum + a, 0);
        result += (sum >= m);
    }
    cout << result << '\n';
}