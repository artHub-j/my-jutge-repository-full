#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

struct Student
{
    int idn;
    string name;
    double
        mark; // The mark is a value between 0 and 10, or -1 that represents NP
    bool repeater;
};

void information(const vector<Student> &es, double &min, double &max,
                 double &avg)
{
    int m = es.size();
    bool repetidors = true;
    min = es[0].mark;
    max = es[0].mark;
    int compt = 0;
    for (unsigned int i = 0; i < m; ++i)
    {
        if (not es[i].repeater)
        {
            repetidors = false;
            avg = avg + es[i].mark;
            if (es[i].mark < min)
            {
                min = es[i].mark;
            }
            else if (es[i].mark > max)
            {
                max = es[i].mark;
            }
            compt++;
        }
    }

    avg = avg / compt;
    if (repetidors)
    {
        avg = -1;
        min = -1;
        max = -1;
    }
}
