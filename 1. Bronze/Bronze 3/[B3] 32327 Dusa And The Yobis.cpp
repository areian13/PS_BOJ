#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int d;
    cin >> d;

    while (true)
    {
        int k;
        cin >> k;

        if (cin.eof() || k >= d)
            break;

        d += k;
    }
    cout << d << '\n';
}