#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        double n, b, m;
        cin >> n >> b >> m;

        if (cin.eof())
            break;

        int result = ceil(log10(m / n) / log10(1 + b / 100));
        cout << result << '\n';
    }
}