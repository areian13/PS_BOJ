#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h;
    cin >> h;

    for (int i = -h / 2; i <= +h / 2; i++)
    {
        for (int j = 0; j < h * 2; j++)
        {
            bool result = (j < h - abs(i) * 2 || h + abs(i) * 2 <= j);
            cout << (result == true ? '*' : ' ');
        }
        cout << '\n';
    }
}