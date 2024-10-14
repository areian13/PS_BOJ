#include <iostream>
#include <array>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<bool, 12> isWhite = { 1,0,1,1,0,1,0,1,1,0,1,0 };
string pitch = "A BC D EF G ";

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> sheet(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sheet[i];
        sheet[i] %= 12;
    }

    for (int i = 0; i < 12; i++)
    {
        int key = i;
        for (int j = 0; j < n; j++)
        {
            key += sheet[j];
            key = (key + 12) % 12;
            if (!isWhite[key])
                break;
        }

        if (isWhite[key])
            cout << pitch[i] << ' ' << pitch[key] << '\n';
    }
}