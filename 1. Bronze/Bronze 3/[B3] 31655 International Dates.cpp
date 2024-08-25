#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string WhereDate(int a, int b, int c)
{
    if (a > 12)
        return "EU";
    if (b > 12)
        return "US";
    return "either";
}

int main()
{
    FastIO;

    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);

    string result = WhereDate(a, b, c);
    cout << result << '\n';
}