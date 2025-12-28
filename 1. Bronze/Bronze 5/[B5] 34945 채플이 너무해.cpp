#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x;
    cin >> x;

    if (x + 2 >= 8)
        cout << "Success!" << '\n';
    else
        cout << "Oh My God!" << '\n';
}