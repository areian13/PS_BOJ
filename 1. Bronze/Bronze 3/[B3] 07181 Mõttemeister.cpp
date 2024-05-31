#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int IsIn(string& pwd, string& guess)
{
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (pwd[j] == guess[i])
            {
                result++;
                break;
            }
        }
    }
    return result;
}

int IsSame(string& pwd, string& guess)
{
    int result = 0;
    for (int i = 0; i < 4; i++)
        result += (pwd[i] == guess[i]);
    return result;
}

int main()
{
    FastIO;

    string pwd;
    int n;
    cin >> pwd >> n;

    while (n--)
    {
        string guess;
        cin >> guess;

        int a = IsIn(pwd, guess);
        int b = IsSame(pwd, guess);
        cout << a << ' ' << b << '\n';
    }
}