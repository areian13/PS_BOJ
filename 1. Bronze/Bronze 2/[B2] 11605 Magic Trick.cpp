#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanOper(int v, vector<pair<string, int>>& opers)
{
    for (auto& [op, x] : opers)
    {
        if (op == "ADD")
            v += x;
        else if (op == "SUBTRACT")
        {
            if (v < x)
                return false;
            v -= x;
        }
        else if (op == "MULTIPLY")
            v *= x;
        else
        {
            if (v % x != 0)
                return false;
            v /= x;
        }
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<pair<string, int>> opers(n);
    for (auto& oper : opers)
        cin >> oper.first >> oper.second;

    int result = 0;
    for (int i = 1; i <= 100; i++)
        result += !CanOper(i, opers);
    cout << result << '\n';
}