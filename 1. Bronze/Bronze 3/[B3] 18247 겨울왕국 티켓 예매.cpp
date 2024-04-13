#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SeatNumOfL4(int n, int m)
{
    if (n < 12 || m < 4)
        return -1;
    return 11 * m + 4;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        int result = SeatNumOfL4(n, m);
        cout << result << '\n';
    }
}