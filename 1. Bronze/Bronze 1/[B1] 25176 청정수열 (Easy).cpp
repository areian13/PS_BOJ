#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Fact(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = Fact(n);
    cout << result << '\n';
}