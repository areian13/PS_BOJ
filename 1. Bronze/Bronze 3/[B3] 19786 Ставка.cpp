#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Value(int a, int c, array<int, 3>& rgb)
{
    return a * (rgb[0] * rgb[0] + rgb[1] * rgb[1] + rgb[2] * rgb[2]) + c * min({ rgb[0],rgb[1],rgb[2] });
}

int main()
{
    FastIO;

    array<string, 3> RGB = { "RED","GREEN","BLUE" };

    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, c;
        cin >> a >> c;

        array<int, 3> rgb;
        for (int i = 0; i < 3; i++)
            cin >> rgb[i];

        int maxValue = Value(a, c, rgb);
        string result;
        for (int i = 0; i < 3; i++)
        {
            rgb[i]++;
            int value = Value(a, c, rgb);
            if (value > maxValue)
            {
                maxValue = value;
                result = RGB[i];
            }
            rgb[i]--;
        }
        cout << result << '\n';
    }
}