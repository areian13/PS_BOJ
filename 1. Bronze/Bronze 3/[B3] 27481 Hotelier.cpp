#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = "0000000000";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L' || s[i] == 'R')
        {
            bool lr = (s[i] == 'R');
            int dir = (lr ? -1 : +1);
            for (int j = 9 * lr; j != 9 * !lr + dir; j += dir)
            {
                if (result[j] == '0')
                {
                    result[j] = '1';
                    break;
                }
            }
        }
        else
            result[s[i] - '0'] = '0';
    }
    cout << result << '\n';
}