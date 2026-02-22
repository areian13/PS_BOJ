#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, e;
    cin >> n >> e;

    int r = 0, c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int d;
        cin >> d;
        r += d;
    }
    for (int i = 0; i < e - 1; i++)
    {
        int d;
        cin >> d;
        c += d;
    }

    int result = ceil(sqrt(r * r + c * c));
    cout << result << '\n';
}