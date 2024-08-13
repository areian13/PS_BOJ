#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        double a, b;
        cin >> a >> b;

        double result = a * 2 / b;
        printf("The height of the triangle is %.2lf units\n", result);
    }
}