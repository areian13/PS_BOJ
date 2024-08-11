#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string test;
    cin >> n >> test;

    int result = 0;
    for (int i = 0; i < n; i += n / 10)
    {
        bool isRight = true;
        for (int j = 0; j < n / 10; j++)
            isRight &= (test[i + j] == 'T');
        result += isRight;
    }
    cout << result << '\n';
}