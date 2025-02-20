#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 5> l;
    for (int i = 0; i < 5; i++)
        cin >> l[i];
    
    int t;
    cin >> t;
    
    array<int, 3> result = { 0,0,0 };
    int i = 0;
    while (t > 0)
    {
        for (int j = 0; j < l[i] && t > 0; j++, t--)
        {
            if (i == 0)
                result[2]++;
            else if (i == 1 && j % 2 == 0)
                result[2]++;
            else if (i == 2)
                result[1]++;
            else if (i == 3)
                result[0]++;
            else if (i == 4)
            {
                result[0]++;
                result[1]++;
            }
        }
        i = (i + 1) % 5;
    }

    for (int i = 0; i < 3; i++)
        cout << result[i] << ' ';
    cout << '\n';
}