#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool Op(int a, string& op, int b)
{
    if (op == ">")
        return a > b;
    if (op == ">=")
        return a >= b;
    if (op == "<")
        return a < b;
    if (op == "<=")
        return a <= b;
    if (op == "==")
        return a == b;
    return a != b;
}

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int a, b;
        string op;
        cin >> a >> op >> b;

        if (op == "E")
            break;

        bool result = Op(a, op, b);
        printf("Case %d: %s\n", ++tc, (result == true ? "true" : "false"));
    }
}