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
    bool repetidors = true;
    min = es[0].mark;
    max = es[0].mark;
    int compt = 0;
    for (unsigned int i = 0; i < es.size(); ++i)
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

int main()
{
    { // vigilar el tipus Estudiant

        struct Estudiant_cntrl
        {
            int dni;
            string nom;
            double nota;
            bool repetidor;
        };

        Student ru;
        Estudiant_cntrl rc;

        // diagnostics en temps de compilacio
        ru.idn = rc.dni;
        ru.name = rc.nom;
        ru.mark = rc.nota;
        rc.repetidor = ru.repeater;

        // diagnostics en temps d'execucio
        if (sizeof(ru) != sizeof(rc))
            throw string("It seems that 'Student' is not well defined");
        if (typeid(ru.idn) != typeid(rc.dni))
            throw string("It seems that 'Student.idn' is not well defined");
        if (typeid(ru.name) != typeid(rc.nom))
            throw string("It seems that 'Student.name' is not well defined");
        if (typeid(ru.mark) != typeid(rc.nota))
            throw string("It seems that 'Student.mark' is not well defined");
        if (typeid(ru.repeater) != typeid(rc.repetidor))
            throw string("It seems that 'Student.repeater' is not well defined");
    }

    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    while (cin >> n)
    {
        vector<Student> es(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> es[i].mark >> es[i].repeater;
        }
        double min, max, avg;
        information(es, min, max, avg);
        cout << min << " " << max << " " << avg << endl;
    }
}
