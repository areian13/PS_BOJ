#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    int sum = 0;
    while (sum <= n)
    {
        sum += result * result + (result + 1) * (result + 1);
        result++;
    }
    result--;

    cout << result << '\n';
}