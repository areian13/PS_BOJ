#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ctoi(char c)
{
    if (('0' <= c && c <= '9'))
        return c - '0';
    return c - 'A' + 10;
}

int ConvertBaseTo10(string& str, int b)
{
    int result = 0;
    int d = str.size();
    int k = 1;
    for (int i = 0; i < d; i++)
    {
        result += ctoi(str[d - i - 1]) * k;
        k *= b;
    }
    return result;
}

int main()
{
    FastIO;

    string n;
    int b;
    cin >> n >> b;

    // ���� stl �Լ��� �ƴ� �͵� �߿������� ���� ������ �� �˾ƾ���.
    int result = ConvertBaseTo10(n, b);
    cout << result << '\n';
}