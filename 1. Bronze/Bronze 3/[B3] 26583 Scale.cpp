#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string str;
    while (getline(cin, str)) // ������� while�� �ȿ� �־�������, �����ͼ¿� ������ ������ ���� Ʋ�Ƚ��ϴٸ� �����Ƿ� �׳� �ۿ� Ǯ����.
    {
        stringstream ss(str);

        vector<int> a;
        string temp;
        a.push_back(1);
        while (ss >> temp)
            a.push_back(stoi(temp));
        a.push_back(1);

        int n = a.size() - 2;

        vector<int> result(n + 2);
        for (int i = 1; i <= n; i++)
            result[i] = a[i - 1] * a[i] * a[i + 1];
        for (int i = 1; i <= n; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}