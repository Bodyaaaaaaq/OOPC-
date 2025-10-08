#include <iostream>
#include <cstring>

using namespace std;

class Car {
private:
    char* brand;
    char* color;
    int power;      
    double volume;  

public:
    Car() {
        brand = new char[10]; 
        strcpy(brand, "N/A");
        color = new char[10];
        strcpy(color, "N/A");
        power = 0;
        volume = 0;
    }

    Car(const char* b, const char* c, int p, double v) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b); 
        color = new char[strlen(c) + 1];
        strcpy(color, c);
        setPower(p);
        setVolume(v);
    }

    ~Car() {
        delete[] brand;
        delete[] color;
    }

    // Геттери і сеттери
    char* getBrand() { return brand; }
    void setBrand(const char* b) {
        delete[] brand;
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
    }

    char* getColor() { return color; }
    void setColor(const char* c) {
        delete[] color;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }

    int getPower() { return power; }
    void setPower(int p) {
        if(p < 0 || p > 2000 ){
            throw invalid_argument("Power can be only 0<=p<=2000 ");
        }
        power = p;
    }

    double getVolume() { return volume; }
    void setVolume(double v) {
        if(v < 0 || v > 10){
            throw invalid_argument("Volume can be only 0<=p<=10 ");
        }
        volume = v;
    }

    Car& operator+=(int addPower){ // +=
        power += addPower;
        return *this;
    }

    void show() {
        cout << "Car: " << brand << ", color: " << color
             << ", power: " << power << " h.p., volume: " << volume << " liters" << endl;
    }
};

ostream& operator<<(ostream& out, Car& c){     // <<
    out << "Car: " << c.getBrand() << ", color: " << c.getColor()
        << ", power: " << c.getPower() << " h.p., volume: " << c.getVolume() << " liters" << endl;
    return out;
}

istream& operator>>(istream& in, Car& c){ // >>
    char tBrand[30];
    char tColor[30];
    int power;
    double volume;

    cout << "Enter the brand: ";
    in >> tBrand;
    cout << "Enter the color: ";
    in >> tColor;
    cout << "Enter power: "; 
    in >> power;
    cout << "Enter volume: ";
    in >> volume;

    c.setBrand(tBrand);
    c.setColor(tColor);
    c.setPower(power);
    c.setVolume(volume);

    return in;
}


void search(Car* cars, int size, const char* color) {
    cout << "Search results for color \"" << color << "\":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(cars[i].getColor(), color) == 0) {
            cout << cars[i];
            found = true;
        }
    }
    if (!found) cout << "No cars with this color found." << endl;
}

void search(Car* cars, int size, int p) {
    cout << "Search results for power = " << p << ":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (cars[i].getPower() == p) {
            cout << cars[i];
            found = true;
        }
    }
    if (!found) cout << "No cars with this power found." << endl;
}


int main() {
    Car cars[3] = {
        Car("BMW", "black", 300, 3.0),
        Car("Audi", "white", 250, 2.5),
        Car("Toyota", "red", 150, 1.8)
    };

    cout << "Cars:\n";
    for (int i = 0; i < 3; i++){
     cout << cars[i];
    }

    int choice;
    cout << "\nSearching car:\n";
    cout << "1 - color\n2 - power\n";
    cout << "Enter the choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            char color[30];
            cout << "Enter the color: ";
            cin >> color;
            search(cars, 3, color);
            break;
        }
        case 2: {
            int power;
            cout << "Enter the power: ";
            cin >> power;
            search(cars, 3, power);
            break;
        }
        default:
            cout << "Error\n";
    }

    Car myCar;
    cout << "\n--- Adding your car ---\n";
    cin >> myCar;
    cout << myCar;

    int n;
    cout << "Enter count of power to increasing: ";
    cin >> n;
    myCar += n;

    cout << "After increasing power:\n";
    cout << myCar;

    return 0;
}
