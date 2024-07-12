#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int coin = 100;
    int result = coin;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;

        coin += v;
        result = max(result, coin);
    }
    cout << result << '\n';
}