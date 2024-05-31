#include <iostream>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        string str;
        cin >> n >> str;

        int y = 0;
        int x = 0;
        for (char& c : str)
        {
            if (c == 'E')
                x++;
            else if (c == 'W')
                x--;
            else if (c == 'N')
                y++;
            else
                y--;
        }
        int result = abs(y) + abs(x);
        cout << result << '\n';;
    }
}