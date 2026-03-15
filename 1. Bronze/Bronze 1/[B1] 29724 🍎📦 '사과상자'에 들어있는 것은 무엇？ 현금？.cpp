#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int g = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        char t;
        int w, h, l;
        cin >> t >> w >> h >> l;

        if (t == 'A')
        {
            int cnt = (w / 12) * (h / 12) * (l / 12);
            g += cnt * 500 + 1'000;
            s += cnt * 4'000;
        }
        else if (t == 'B')
            g += 120 * 50;
    }
    cout << g << '\n' << s << '\n';
}