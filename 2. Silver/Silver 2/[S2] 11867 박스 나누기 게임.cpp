#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    bool result = ~n % 2 || ~m % 2;
    cout << (result ? 'A' : 'B') << '\n';
}