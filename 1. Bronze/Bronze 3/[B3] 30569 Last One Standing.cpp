#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h1, d1, t1, h2, d2, t2;
    cin >> h1 >> d1 >> t1 >> h2 >> d2 >> t2;

    int c1 = 0;
    int c2 = 0;
    while (h1 > 0 && h2 > 0)
    {
        if (c1 == 0)
        {
            h2 -= d1;
            c1 = t1;
        }
        c1--;

        if (c2 == 0)
        {
            h1 -= d2;
            c2 = t2;
        }
        c2--;
    }
    string result = (h1 <= 0 && h2 <= 0 ? "draw" : (h1 > 0 ? "player one" : "player two"));
    cout << result << '\n';
}