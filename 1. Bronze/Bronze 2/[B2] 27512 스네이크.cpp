#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = n * m - (n % 2 == 1 && m % 2 == 1);
    cout << result << '\n';
}