#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int q;
    cin >> q;

    for (int tc = 1; tc <= q; tc++)
    {
        int a, b;
        cin >> a >> b;

        int dic = (a < b ? b - a : b + 43 - a);
        int doc = (a > b ? a - b : a + 43 - b);

        if (dic < doc)
            cout << "Inner circle line" << '\n';
        else if (dic > doc)
            cout << "Outer circle line" << '\n';
        else
            cout << "Same" << '\n';
    }
}