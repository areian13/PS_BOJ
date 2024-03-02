#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Student
{
    string name;
    int size;

    friend bool operator<(const Student& a, const Student& b)
    {
        return a.size < b.size;
    }
};

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == -1)
            break;

        vector<Student> student(n);
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z >> student[i].name;
            student[i].size = x * y * z;
        }
        sort(student.begin(), student.end());

        printf("%s took clay from %s.\n", student[n - 1].name.c_str(), student[0].name.c_str());
    }
}