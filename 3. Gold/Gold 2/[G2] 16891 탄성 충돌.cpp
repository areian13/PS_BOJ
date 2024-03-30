#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountCollision(double n)
{
    n *= n;

    int result = 0;
    double a = 0;
    double b = INT_MIN;
    while (true)
    {
        if (0 <= a && a <= b)
            break;

        double temp = (1 - n) / (1 + n) * a + 2 * n / (1 + n) * b;
       
        b = 2 / (1 + n) * a - (1 - n) / (1 + n) * b;
        a = temp;

        result++;
        if (a < 0)
        {
            a *= -1;
            result++;
        }
    }
    return result;
}

int main()
{
    FastIO;

    double n;
    cin >> n;

    int result = CountCollision(n);
    cout << result << '\n';
}