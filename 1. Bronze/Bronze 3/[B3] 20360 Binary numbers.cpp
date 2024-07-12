#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
            cout << result << ' ';
        n /= 2;
        result++;
    }
    cout << '\n';
}