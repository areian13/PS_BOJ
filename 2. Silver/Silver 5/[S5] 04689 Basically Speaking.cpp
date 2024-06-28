#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string DecConversion(string n, int fd, int td)
{
    static string d16 = "0123456789ABCDEF";

    long long d10 = stoll(n, nullptr, fd);
    string result = "";
    do
    {
        result += d16[d10 % td];
        d10 /= td;
    } while (d10 > 0);

    int k = result.size();
    if (k > 7)
    {
        result = "RORRE";
        k = result.size();
    }
    result += string(7 - k, ' ');

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        string n;
        int fd, td;
        cin >> n >> fd >> td;

        if (cin.eof())
            break;

        string result = DecConversion(n, fd, td);
        cout << result << '\n';
    }
}