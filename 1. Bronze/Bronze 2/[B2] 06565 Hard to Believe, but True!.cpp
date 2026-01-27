#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        string a, b, c;
        int cnt = 0;
        for (char o : s)
        {
            if (o == '+' || o == '=')
            {
                cnt++;
                continue;
            }

            if (cnt == 0)
                a += o;
            else if (cnt == 1)
                b += o;
            else
                c += o;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());

        bool result = (stoi(a) + stoi(b) == stoi(c));
        if (result == true)
            cout << "True" << '\n';
        else
            cout << "False" << '\n';

        if (s == "0+0=0")
            break;
    }
}