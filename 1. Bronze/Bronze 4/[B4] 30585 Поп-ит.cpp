#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;


int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = 0;
    for (int i = 0; i < n * m; i++)
    {
        char c;
        cin >> c;

        result += (c == '0');
    }
    result = min(result, n * m - result);
    cout << result << '\n';
}