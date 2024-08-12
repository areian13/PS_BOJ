#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

double SaledPrice(double n, double p)
{
    double result = 0;
    if (n < 5)
        result = p;
    else if (n < 10)
        result =  p - 500;
    else if (n < 15)
        result =  min(p - 500, p * 0.9);
    else if (n < 20)
        result =  min(p - 2000, p * 0.9);
    else
        result =  min(p - 2000, p * 0.75);

    return max(result, .0);
}
int main()
{
    FastIO;

    int n, p;
    cin >> n >> p;

    double result = SaledPrice(n, p);
    cout << result << '\n';
}