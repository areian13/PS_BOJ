#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Supernova(int n, int m)
{
    m--;
    string result = "SN " + to_string(n);
    if (m < 26) result += (m + 'A');
    else
    {
        m -= 26;
        result += m / 26 + 'a';
        result += m % 26 + 'a';
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    string result = Supernova(n, m);
    cout << result << '\n';
}