#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHarshad(int n)
{
    int sum = 0;
    int k = n;
    while (k > 0)
    {
        sum += k % 10;
        k /= 10;
    }
    return (n % sum == 0);
}

int Harshad(int n)
{
    while (!IsHarshad(n))
        n++;
    return n;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = Harshad(n);
    cout << result << '\n';
}