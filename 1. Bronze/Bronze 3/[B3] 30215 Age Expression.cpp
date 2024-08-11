#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanCalculateAge(int o, int a, int k)
{
    for (int i = 1; i * a <= o; i++)
    {
        for (int j = 1; j * k <= o; j++)
        {
            int age = i * a + j * k;
            if (age == o)
                return true;

            if (age > o)
                break;
        }
    }
    return false;
}

int main()
{
    FastIO;

    int o, a, k;
    cin >> o >> a >> k;

    bool result = CanCalculateAge(o, a, k);
    cout << result << '\n';
}