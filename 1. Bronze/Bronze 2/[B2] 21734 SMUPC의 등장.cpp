#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    for (char c : s)
    {
        int temp = c, sum = 0;
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }

        cout << string(sum, c) << '\n';
    }
}