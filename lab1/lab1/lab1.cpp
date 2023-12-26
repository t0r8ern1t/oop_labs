#include <iostream>
#include <functional>

using namespace std;

class ICalc 
{
protected:
    double m_x0, m_step;
    function<double(double)> m_f;

public:
    ICalc(double x0, function<double(double)>f, double step)
    {
        m_x0 = x0;
        m_step = step;
        m_f = move(f);
    }

    virtual double Calcdiff() { return 0; };
};

class Calcleft : ICalc
{
public:
    Calcleft(double x0, function<double(double)>f, double step = 0) : ICalc(x0, f, step) {};

    double Calcdiff() override
    {
        double fl = (m_f(m_x0) - m_f(m_x0 - m_step)) / m_step;
        return fl;
    };
};

class Calcright : ICalc
{
public:
    Calcright(double x0, function<double(double)>f, double step = 0) : ICalc(x0, f, step) {};

    double Calcdiff() override
    {
        double fr = (m_f(m_x0 + m_step) - m_f(m_x0)) / m_step;
        return fr;
    };
};

class Calcmiddle : ICalc
{
public:
    Calcmiddle(double x0, function<double(double)>f, double step = 0) : ICalc(x0, f, step) {};

    double Calcdiff() override
    {
        double fc = (m_f(m_x0 + m_step) - m_f(m_x0 - m_step)) / (2 * m_step);
        return fc;
    };
};


function<double(double)>f = [](double x) {
    return x*x;
};


int main()
{
    setlocale(LC_ALL, "Russian");
    double x0, step;
    cout << "Введите х0" << endl;
    cin >> x0;
    cout << "Введите шаг" << endl;
    cin >> step;

    auto calcr = make_unique<Calcright>(Calcright(x0, f, step));
    auto calcl = make_unique<Calcleft>(Calcleft(x0, f, step));
    auto calcm = make_unique<Calcmiddle>(Calcmiddle(x0, f, step));

    cout << "Правая производная: " << calcr->Calcdiff() << endl;
    cout << "Левая производная: " << calcl->Calcdiff() << endl;
    cout << "Средняя производная: " << calcm->Calcdiff() << endl;
}
