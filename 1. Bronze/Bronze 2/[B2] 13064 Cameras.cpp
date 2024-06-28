#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define among(a, to, z) (a <= to && to <= z)

bool IsRightNum(string& num)
{
    if (num.size() != 8)
        return false;
    for (int i : { 0,1,2,3,5,6,7 })
    {
        if (!among('1', num[i], '9'))
            return false;
    }
    if (num[0] != num[1])
        return false;
    if (!among('A', num[4], 'Z'))
        return false;

    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    while (n--)
    {
        string num;
        cin >> num;

        if (IsRightNum(num))
            cout << num << '\n';
    }
}