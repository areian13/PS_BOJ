#include <iostream>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (char& c : s)
        {
            if (c == '0' || c == '6')
                c = '9';
        }
        sum += min(stoi(s), 100);
    }

    int result = round(1. * sum / n);
    cout << result << '\n';
}