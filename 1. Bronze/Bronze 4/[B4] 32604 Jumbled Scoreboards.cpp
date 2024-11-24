#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int pl = 0, pr = 0;
    bool isSorted = true;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        isSorted &= (l >= pl && r >= pr);
        pl = l, pr = r;
    }

    if (isSorted)
        cout << "yes" << '\n';
    else
        cout << "no" << '\n';
}