#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsInc(array<int, 5>& a)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] >= a[i + 1])
            return false;
    }
    return true;
}
void Print(array<int, 5>& a)
{
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

int main()
{
    FastIO;

    array<int, 5> a;
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    while (!IsInc(a))
    {
        for (int i = 0; i < 4; i++)
        {
            if (a[i] >= a[i + 1])
            {
                swap(a[i], a[i + 1]);
                Print(a);
            }
        }
    }
}