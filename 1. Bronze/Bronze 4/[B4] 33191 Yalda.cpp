#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int b, w, p, n;
    cin >> b >> w >> p >> n;

    if (b >= w)
        cout << "Watermelon" << '\n';
    else if (b >= p)
        cout << "Pomegranates" << '\n';
    else if (b >= n)
        cout << "Nuts" << '\n';
    else
        cout << "Nothing" << '\n';
}