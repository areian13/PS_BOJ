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

    int result = 0, bonus = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'O')
        {
            result += i + 1 + bonus;
            bonus++;
        }
        else
            bonus = 0;
    }
    cout << result << '\n';
}