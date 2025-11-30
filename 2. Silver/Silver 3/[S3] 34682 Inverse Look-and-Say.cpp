#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string f(string x)
{
    int l = x.size();
    string result = "";
    for (int i = 0; i < l; i++)
    {
        int cnt = 0;
        while (i + cnt < l && x[i] == x[i + cnt])
            cnt++;

        if (cnt > 9)
            return "-1";
        result += to_string(cnt) + x[i];
        i += cnt - 1;
    }
    return result;
}

string fr(string n)
{
    int l = n.size();
    if (l & 1) return "-1";
    if (n[1] == '0') return "-1";

    string result = "";
    for (int i = 0; i < l; i += 2)
    {
        for (int j = 0; j < n[i] - '0'; j++)
            result += n[i + 1];
    }

    if (n == f(result)) return result;
    return "-1";
}

int main()
{
    FastIO;

    string n;
    cin >> n;

    string result = fr(n);
    cout << result << '\n';
}