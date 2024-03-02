#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int h;
        cin >> h;

        if (h == 0)
            break;

        int result = h;
        while (h != 1)
        {
            h = (h % 2 == 0 ? h / 2 : h * 3 + 1);
            result = max(result, h);
        }
        cout << result << '\n';
    }
}