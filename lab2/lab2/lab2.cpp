#include <iostream>
#include <string>

using namespace std;

class Ratio
{
public:
    Ratio() {
        numer = 0;
        denom = 0;
        whole = 0;
    }

    Ratio(int n, int d) {
        numer = n;
        denom = d;
        // значение целой части дроби присваевается только при вызов метода wholePart()
        whole = 0;
    }

    int getNumer() const { return numer; }
    int getDenom() const { return denom; }
    void set(int n, int d) {
        numer = n;
        denom = d;
    }

    // вывод в консоль
    void print() {
        if (whole != 0)
            cout << whole << "+";
        cout << numer << '/' << denom << endl;
    }

    // ввод с консоли
    void read() {
        string str;
        getline(cin, str);
        int sep = str.find('/');
        this->set(stoi(str.substr(0, sep)), stoi(str.substr(sep + 1)));
    }


    // сокращение
    void simplify() {
        for (int i = 1; i <= min(abs(numer), abs(denom)); ++i) {
            if (numer % i == 0 && denom % i == 0) {
                numer /= i;
                denom /= i;
            }
        }
    }
    
    // перевод в десятичную дробь
    float toDecimal() {
        cout << "перевод в десятичную дробь" << endl;
        float tmp = float(numer) / float(denom);
        return tmp;
    }

    // выделение целой части
    Ratio wholePart() {
        cout << "выделение целой части" << endl;
        Ratio tmp;
        if (numer < denom)
            tmp = *this;
        else {
            tmp.whole = numer / denom;
            tmp.numer = numer - denom * tmp.whole;
            tmp.denom = denom;
        }
        return tmp;
    }

    //перегрузка операторов и методы, ссылающиеся на перегрузку
    void operator=(const Ratio& r) {
        numer = r.getNumer();
        denom = r.getDenom();
    }

    Ratio operator+(const Ratio& r) {
        Ratio tmp;
        tmp.numer = numer * r.getDenom() + denom * r.getNumer();
        tmp.denom = denom * r.getDenom();
        tmp.simplify();
        return tmp;
    }

    Ratio add(const Ratio& r) {
        cout << "сложение" << endl;
        Ratio tmp = *this + r;
        return tmp;
    }

    Ratio operator-(const Ratio& r) {
        Ratio tmp;
        tmp.numer = numer * r.getDenom() - denom * r.getNumer();
        tmp.denom = denom * r.getDenom();
        tmp.simplify();
        return tmp;
    }

    Ratio subtract(const Ratio& r) {
        cout << "вычитание" << endl;
        Ratio tmp = *this - r;
        return tmp;
    }

    Ratio operator*(const Ratio& r) {
        Ratio tmp;
        tmp.numer = numer * r.getNumer();
        tmp.denom = denom * r.getDenom();
        tmp.simplify();
        return tmp;
    }

    Ratio multiply(const Ratio& r) {
        cout << "умножение" << endl;
        Ratio tmp = *this * r;
        return tmp;
    }

    Ratio operator/(const Ratio& r) {
        Ratio tmp;
        tmp.numer = numer * r.getDenom();
        tmp.denom = denom * r.getNumer();
        tmp.simplify();
        return tmp;
    }

    Ratio divide(const Ratio& r) {
        cout << "деление" << endl;
        Ratio tmp = *this / r;
        return tmp;
    }

private:
    int whole;
    int numer;
    int denom;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Ratio x, y;
    cout << "введите первую дробь: ";
    x.read();
    cout << "введите вторую дробь: ";
    y.read();
    cout << endl;
    Ratio z = x.add(y);
    z.print();
    z.wholePart().print();
    cout << z.toDecimal() << endl;;
    x.subtract(y).print();
    x.multiply(y).print();
    x.divide(y).print();
    return 0;
}