#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHappy(char c)
{
    static string happy = "HAPPY";

    for (char h : happy)
    {
        if (c == h)
            return true;
    }
    return false;
}
bool IsSad(char c)
{
    static string sad = "SAD";

    for (char s : sad)
    {
        if (c == s)
            return true;
    }
    return false;
}

double HappyCoef(string& s)
{
    int ph = 0;
    int ps = 0;

    for (char c : s)
    {
        if (c == ' ')
            continue;

        ph += IsHappy(c);
        ps += IsSad(c);
    }
    
    if (ph == 0 && ps == 0)
        return 50;
    return round((double)ph * 10000 / (ph + ps) / 100);
}

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    double result = HappyCoef(s);
    printf("%.2lf\n", result);
}