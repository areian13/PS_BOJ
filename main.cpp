#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int 학번 = 202211441;
    int CODE = ((학번 % 10000) * 3897 + (학번 / 100000) * (학번 / 100000)) % 10000;
    cout << CODE << '\n';
}