#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Alice" << '\n';
        cout << n - 1 << '\n';
    }
    else
        cout << "Bob" << '\n';
}