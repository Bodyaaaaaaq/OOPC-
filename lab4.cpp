#include <iostream>
#include <fstream>
#include <cmath> 

using namespace std;


class Cube {
private:
    double side;
public:
    Cube(double s = 1.0) : side(s) {}

    double volume() const {
        return pow(side, 3);
    }

    double surfaceArea() const {
        return 6 * pow(side, 2);
    }

    void printInfo(ostream &out) const {
        out << "Cube:\n";
        out << "   Side: " << side << endl;
        out << "   Volume: " << volume() << endl;
        out << "   Surface: " << surfaceArea() << endl;
    }
};

class Sphere {
private:
    double radius;
public:
    Sphere(double r = 1.0) : radius(r) {}

    double volume() const {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }

    double surfaceArea() const {
        return 4 * M_PI * pow(radius, 2);
    }

    void printInfo(ostream &out) const {
        out << "Sphere:\n";
        out << "   Radius: " << radius << endl;
        out << "   Volume: " << volume() << endl;
        out << " Surface : " << surfaceArea() << endl;
    }
};

class SphereInCube : public Cube, public Sphere {
public:
    SphereInCube(double sideLength)
        : Cube(sideLength), Sphere(sideLength / 2.0) {}

    void printInfo(ostream &out) const {
        out << "Sphere In Cube:\n ";
        out << "----------------------------------\n";
        Cube::printInfo(out);
        out << endl;
        Sphere::printInfo(out);
        out << "----------------------------------\n";
    }
};
ostream& operator<<(ostream& out, const SphereInCube& figure) {
    figure.printInfo(out);
    return out; 
}


int main() {
    double side;
    cout << "Enter side of cube: ";
    cin >> side;
    SphereInCube figure(side);
    ofstream file("result.txt");
    cout << endl;
    cout << figure; 
    file << "Result of calculating: \n";

    file << figure; 

    file.close();
    cout << "\nResult succesfuly exported in <result.txt>\n";
    return 0;
}