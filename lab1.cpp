#include <iostream>
#include <cmath>

using namespace std;

double getb(double x, double y, double z) {
    return (pow(abs(y + x), 0.2)) / (pow(abs(z), 1.34)) + (pow((y - z), 2)) / (1 + pow(sin(z), 2)) + (pow(abs(z - y), 3)) / (z / cos(pow(x, 2)));
}

double geta(double x, double y, double z, double b) {
    return (sqrt(pow(abs(pow(x, 2) - 1), 0.3)) - cbrt(abs(sin(y + 2 * b)))) / (1 + (x / 1) + (pow(y, 2) / 4) + (pow(z, 3) / 27));
}

int main(){
    double x=0.48, y=0.47,z=-1.32;
    double b=getb(x,y,z);
    double a=geta(x,y,z,b);
    cout << "Task 1: "<<endl;
    cout << "Result b = " << b<<endl;
    cout << "Result a = " << a<<endl;

    cout << "____________________________________"<<endl;
    cout << "Task 2: "<<endl;
    for(double x1=-1; x1<=1; x1+=0.2){
         double b1=getb(x1,y,z);
            double a1=geta(x1,y,z,b1);
            cout << "x = " << x1 << " b = " << b1 << " a = " << a1<<endl;
            cout << "------------------------------------"<<endl;
    } 
return 0;
}