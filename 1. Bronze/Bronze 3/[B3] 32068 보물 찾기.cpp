#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int l, r, s;
        cin >> l >> r >> s;

        int dr = r - s;
        int dl = s - l;

        int result = (dr <= dl ? dr * 2 : dl * 2 + 1);
        cout << result << '\n';
    }
}