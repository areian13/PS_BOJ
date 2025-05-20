#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Repunit(int x)
{
    int result = 0;
    for (int i = 0; i < x; i++)
    {
        result *= 10;
        result += 1;
    }
    return result;
}

int main()
{
    FastIO;

    int x, y;
    cin >> x >> y;

    int result = Repunit(x) + Repunit(y);
    cout << result << '\n';
}