#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, c;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;

        cnt += c;
    }

    int result = cnt % 2;
    cout << result << '\n';
}