#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int a = 1;
    int b = 1;

    while (n > (a + 1) * (b + 1))
        (a > b ? b : a)++;
    
    int result = (a + b) * 2;
    cout << result << '\n';
}