#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    cout << n << '\n';
    for (int i = 0; i < n - 1; i++)
        cout << i + 1 << ' ';
    cout << 997 << '\n';
}