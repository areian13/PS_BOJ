#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, m;
    cin >> a >> m;

    int result = 0;
    while (result * a % m != 1)
        result++;
    cout << result << '\n';
}