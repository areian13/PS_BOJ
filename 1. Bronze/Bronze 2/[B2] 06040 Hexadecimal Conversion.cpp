#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int htod(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

string HexToBin(string hex)
{
    string bin = "";
    for (char c : hex)
    {
        int d = htod(c);
        string b = "";
        for (int i = 0; i < 4; i++)
        {
            b += (d % 2) + '0';
            d /= 2;
        }
        reverse(b.begin(), b.end());
        bin += b;
    }
    return bin;
}

string BinToOct(string bin)
{
    int b = bin.size();

    string oct = "";
    for (int i = b - 1; i >= 0; i -= 3)
    {
        int o = 0;
        int d = 1;
        for (int j = 0; j < 3 && i - j >= 0; j++)
        {
            o += (bin[i - j] - '0') * d;
            d *= 2;
        }
        oct += (o + '0');
    }

    while (oct.size() > 1 && oct.back() == '0')
        oct.pop_back();
    reverse(oct.begin(), oct.end());
    return oct;
}

int main()
{
    FastIO;

    string hex;
    cin >> hex;

    string result = BinToOct(HexToBin(hex));
    cout << result << '\n';
}