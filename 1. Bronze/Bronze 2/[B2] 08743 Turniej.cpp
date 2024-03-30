#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int z;
    cin >> z;

    while (z--)
    {
        int n, k;
        cin >> n >> k;

        int result = (n >= k ? k - 1 : n);
        cout << result << '\n';
    }
}