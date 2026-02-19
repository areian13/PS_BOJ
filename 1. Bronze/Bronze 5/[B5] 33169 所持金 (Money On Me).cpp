#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int result = a * 1'000 + b * 10'000;
    cout << result << '\n';
}