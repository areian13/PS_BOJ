#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string BestCard(int g, int s, int c)
{
    int p = 3 * g + 2 * s + c;

    string result = "";
    if (p >= 8)
        result += "Province or ";
    else if (p >= 5)
        result += "Duchy or ";
    else if (p >= 2)
        result += "Estate or ";

    if (p >= 6)
        result += "Gold";
    else if (p >= 3)
        result += "Silver";
    else
        result += "Copper";

    return result;
}

int main()
{
    FastIO;

    int g, s, c;
    cin >> g >> s >> c;

    string result = BestCard(g, s, c);
    cout << result << '\n';
}