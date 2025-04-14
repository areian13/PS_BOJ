#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Elevators(string& s, int n)
{
    if (s == "residential")
    {
        if (n == 1)
            return 0;
        if (n <= 5)
            return 1;
        if (n <= 10)
            return 2;
        if (n <= 15)
            return 3;
        return 4;
    }
    if (s == "commercial")
    {
        if (n == 1)
            return 0;
        if (n <= 7)
            return 1;
        if (n <= 14)
            return 2;
        return 3;
    }
    if (n == 1)
        return 0;
    if (n <= 4)
        return 1;
    if (n <= 8)
        return 2;
    if (n <= 12)
        return 3;
    if (n <= 16)
        return 4;
    return 5;
}

int main()
{
    FastIO;

    string s;
    int n;
    cin >> s >> n;

    int result = Elevators(s, n);
    cout << result << '\n';
}