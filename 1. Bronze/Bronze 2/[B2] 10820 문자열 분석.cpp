#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (cin.eof())
            break;

        array<int, 4> result = { 0, };
        for (char c : s)
        {
            if ('a' <= c && c <= 'z')
                result[0]++;
            else if ('A' <= c && c <= 'Z')
                result[1]++;
            else if ('0' <= c && c <= '9')
                result[2]++;
            else
                result[3]++;
        }

        for (int i = 0; i < 4; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}