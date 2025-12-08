#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int n = a.size();
    string And, Or, Xor, NotA, NotB;
    And = Or = Xor = NotA = NotB = string(n, '0');
    for (int i = 0; i < n; i++)
    {
        bool x = a[i] - '0', y = b[i] - '0';
        And[i] = (x & y) + '0';
        Or[i] = (x | y) + '0';
        Xor[i] = (x ^ y) + '0';
        NotA[i] = !x + '0';
        NotB[i] = !y + '0';
    }
    cout << And << '\n';
    cout << Or << '\n';
    cout << Xor << '\n';
    cout << NotA << '\n';
    cout << NotB << '\n';
}