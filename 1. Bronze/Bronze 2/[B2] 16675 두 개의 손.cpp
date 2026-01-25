#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsBig(char a, char b)
{
    if (a == 'P') return b == 'S';
    if (a == 'S') return b == 'R';
    return b == 'P';
}

int main()
{
    FastIO;

    char ml, mr, tl, tr;
    cin >> ml >> mr >> tl >> tr;

    if (ml == mr && (IsBig(ml, tl) || IsBig(ml, tr)))
        cout << "TK" << '\n';
    else if (tl == tr && (IsBig(tl, ml) || IsBig(tl, mr)))
        cout << "MS" << '\n';
    else
        cout << '?' << '\n';
}