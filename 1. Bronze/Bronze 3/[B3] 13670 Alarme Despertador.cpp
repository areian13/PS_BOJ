#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;

        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break;

        int result = (24 * 60 + h2 * 60 + m2 - h1 * 60 - m1) % (24 * 60);
        cout << result << '\n';
    }
}