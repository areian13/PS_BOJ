#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> fib(21);

string Clong(int c)
{
    string s = "";
    for (int i = 0; i < c; i++)
        s += "long";
    return s;
}

int main()
{
    FastIO;

    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 20; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int n;
    string s;
    cin >> n >> s;

    long long result = 1;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        while (s.substr(i, (c + 1) * 4) == Clong(c + 1))
            c++;

        result *= fib[c];

        i += c * 4;
    }
    cout << result << '\n';
}