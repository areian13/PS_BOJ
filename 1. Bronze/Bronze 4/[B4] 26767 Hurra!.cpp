#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Hurra(int n)
{
    if (n % 77 == 0)
        return "Wiwat!";
    if (n % 11 == 0)
        return "Super!";
    if (n % 7 == 0)
        return "Hurra!";
    return to_string(n);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string result = Hurra(i);
        cout << result << '\n';
    }
}