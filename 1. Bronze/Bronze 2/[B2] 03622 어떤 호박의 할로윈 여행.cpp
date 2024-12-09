#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanTwoRing(int A, int a, int B, int b, int P)
{
    if (A > B)
    {
        swap(A, B);
        swap(a, b);
    }

    if (A + B <= P)
        return true;
    if (B > P)
        return false;
    if (A > b)
        return false;
    return true;
}

int main()
{
    FastIO;

    int A, a, B, b, P;
    cin >> A >> a >> B >> b >> P;

    bool result = CanTwoRing(A, a, B, b, P);
    if (result)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}