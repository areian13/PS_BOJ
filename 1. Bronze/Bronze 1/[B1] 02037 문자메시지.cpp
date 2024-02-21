#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 26

int main()
{
    FastIO;

    array<int, SIZE> number =
    {
        2,2,2,
        3,3,3,
        4,4,4,
        5,5,5,
        6,6,6,
        7,7,7,7,
        8,8,8,
        9,9,9,9
    };

    array<int, SIZE> cnt =
    {
        1,2,3,
        1,2,3,
        1,2,3,
        1,2,3,
        1,2,3,
        1,2,3,4,
        1,2,3,
        1,2,3,4
    };

    int p, w;
    cin >> p >> w;

    cin.ignore();
    string str;
    getline(cin, str);

    int n = str.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            if (i > 0 && ('A' <= str[i - 1] && str[i - 1] <= 'Z'))
            {
                if (number[str[i] - 'A'] == number[str[i - 1] - 'A'])
                    result += w;
            }
            result += p * cnt[str[i] - 'A'];
        }
        else
            result += p;
    }
    cout << result << '\n';
}