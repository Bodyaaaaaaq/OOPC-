#include <iostream>
#include <cmath>

using namespace std;

class Body {
public:
    virtual double volume(){return 0;}
    virtual void printInfo() = 0;          
};


class Parallelepiped : public Body {
private:
    double a, b, c;
public:
       Parallelepiped(double aa, double bb, double cc) {
        a = aa;
        b = bb;
        c = cc;
       }

    void printInfo() {
        cout << "Parallelepiped:\n";
        cout << "  a = " << a << ", b = " << b << ", c = " << c << endl;
        cout << "  Volume = " << volume() << "\n\n";
    }
};


class Pyramid : public Body {
private:
    double a, b, h;
public:
    Pyramid(double aa, double bb, double hh) {
        a = aa;
        b = bb;
        h = hh;
    }

    double volume() {
        return (a * b * h) / 3.0;
    }

    void printInfo() {
        cout << "Pyramid:\n";
        cout << "  a = " << a << ", b = " << b << ", h = " << h << endl;
        cout << "  Volume = " << volume() << "\n\n";
    }
};




class Sphere : public Body {
private:
    double r;
public:
    Sphere(double rr) {
        r = rr;
    }

    double volume() {
        return (4.0 / 3.0) * 3.14 * r * r * r;
    }

    void printInfo() {
        cout << "Sphere:\n";
        cout << "  r = " << r << endl;
        cout << "  Volume = " << volume() << "\n\n";
    }
};

int main() {
    Body* arr[4];

    arr[0] = new Parallelepiped(2, 3, 4);
    arr[1] = new Pyramid(3, 4, 6);
    arr[2] = new Sphere(1);

    cout << "=== Results ===\n\n";
    for (int i = 0; i < 3; i++) {
        arr[i]->printInfo();
    }

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    return 0;
}
