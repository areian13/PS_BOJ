#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHarshad(int n)
{
    string sNum = to_string(n);
    int d = sNum.size();

    int sum = 0;
    for (int i = 0; i < d; i++)
        sum += (sNum[i] - '0');
    return (n % sum == 0);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = n;
    while (!IsHarshad(result))
        result++;

    cout << result << '\n';
}