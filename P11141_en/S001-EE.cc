#include <typeinfo>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Student
{
    int idn;
    string name;
    double mark; // The mark is a value between 0 and 10, or -1 that represents NP
    bool repeater;
};

void information(const vector<Student> &es, double &min, double &max, double &avg)
{
    for (unsigned int i = 0; i < es.size(); i++)
    {
        if (es[i].mark < es[i + 1].mark)
            min = es[i].mark;
        if (i == es.size())
            i--;
    }
    for (unsigned int i = 0; i < es.size(); i++)
    {
        if (es[i].mark > es[i + 1].mark)
            max = es[i].mark;
        if (i == es.size())
            i--;
    }
    int sum = 0;
    unsigned int i = 0;
    while (i < es.size())
    {
        sum = sum + es[i].mark;
        i++;
    }
    avg = sum / i;
}

// int main()
// {
//     int n;
//     while (cin >> n)
//     {
//         vector<Student> es(n);
//         for (int i = 0; i < n; ++i)
//         {
//             cin >> es[i].mark >> es[i].repeater;
//         }
//         double min, max, avg;
//         information(es, min, max, avg);
//         cout << min << " " << max << " " << avg << endl;
//     }
// }