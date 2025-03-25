#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += (i % a == 0 && i % b != 0);
        result += (i % a != 0 && i % b == 0);
    }
    cout << result << '\n';
}