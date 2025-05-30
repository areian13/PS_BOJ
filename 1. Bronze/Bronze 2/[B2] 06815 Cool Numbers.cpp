#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int result = 0;
    for (int i = 1; i * i * i * i * i * i <= b; i++)
        result += (a <= i * i * i * i * i * i);
    cout << result << '\n';
}