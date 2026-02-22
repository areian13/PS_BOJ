#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Clover(int a, int b)
{
    int result = 0;
    while (!(a * 3 <= b && b <= a * 4))
    {
        if (a * 3 > b) b++;
        else a++;
        result++;
    }
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int a, b;
        cin >> a >> b;

        int result = Clover(a, b);
        cout << result << '\n';
    }
}