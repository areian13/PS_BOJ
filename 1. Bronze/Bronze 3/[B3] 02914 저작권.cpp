#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, i;
    cin >> a >> i;

    int result = a * (i - 1) + 1;
    cout << result << '\n';
}