#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> p = {
    13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
};

bool Is11(string& s)
{
    int sum = 0, sign = +1;
    for (char c : s)
    {
        sum += (c - '0') * sign;
        sign *= -1;
    }
    return sum % 11 == 0;
}

string Mul11(int n)
{
    string result = "";
    for (int i = 0; i < n - 1; i++)
        result += "13";

    for (int q : p)
    {
        result += to_string(q);
        if (Is11(result))
            return result;
        result.pop_back();
        result.pop_back();
    }
    return "-1";
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = Mul11(n);
    cout << result << '\n';
}