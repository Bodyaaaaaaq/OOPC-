#include <iostream>
#include <cstring>

using namespace std;

class Engine {
    private:
    double volume;
    int power;
    char* serialNumber;

    public:
    Engine(){
        volume=0;
        power=0;
        serialNumber=new char[10];
        strcpy(serialNumber,"N/A");
    }
    Engine(double v, int p, const char* s){ 
        volume=v;
        power=p;
        serialNumber=new char[strlen(s)+1];
        strcpy(serialNumber,s);
    }
    ~Engine(){ 
        delete[] serialNumber;
    }
    double getVolume(){
        return volume;
    }
    void setVolume(double v){
        volume=v;
    }
    int getPower(){
        return power;
    }
    void setPower(int p){
        power=p;
    }
    char* getSerialNumber(){
        return serialNumber;
    }
    void setSerialNumber(const char* s){
        delete[] serialNumber;
        serialNumber=new char[strlen(s)+1];
        strcpy(serialNumber,s);
    }
    void show() {
        cout << "Engine: " << volume << " liter, " << power << " h.p., serial number: " << serialNumber << endl;
    }

};

class Car{
    private:
    Engine engine;
    char* brand;
    char* color;
    char* registrationNumber;
    public:
    Car(){
        brand=new char[10];
        strcpy(brand,"N/A");
        color=new char[10];
        strcpy(color,"N/A");
        registrationNumber=new char[10];
        strcpy(registrationNumber,"N/A");
    }

    Car(const char* b, const char* c, const char* r, const Engine& e){
        brand=new char[strlen(b)+1];
        strcpy(brand,b);
        color=new char[strlen(c)+1];
        strcpy(color,c);
        registrationNumber=new char[strlen(r)+1];
        strcpy(registrationNumber,r);
        engine=e;
    }
    ~Car(){ 
        delete[] brand;
        delete[] color;
        delete[] registrationNumber;
    }
    char* getBrand(){
        return brand;
    }
    void setBrand(const char* b){
        delete[] brand;
        brand=new char[strlen(b)+1];
        strcpy(brand,b);
    }
    char* getColor(){
        return color;
    }
    void setColor(const char* c){
        delete[] color;
        color=new char[strlen(c)+1];
        strcpy(color,c);
    }
    char* getRegistrationNumber(){
        return registrationNumber;
    }
    void setRegistrationNumber(const char* r){
        delete[] registrationNumber;
        registrationNumber=new char[strlen(r)+1];
        strcpy(registrationNumber,r);
    }
    Engine& getEngine(){
        return engine;
    }
    void setEngine(const Engine& eng){
        engine=eng;
    }
    void reassignNumber(const char* newNumber){
        setRegistrationNumber(newNumber);
    }
    void repaint(const char* newColor){
        setColor(newColor);
    }
    void show(){
        cout << "Car: " << brand << ", color: " << color << ", Registration Number: " << registrationNumber << endl;
        engine.show();
    }

};

int main(){
    Engine eng1(2.4, 250, "5J6TF3H57FS123456");
    Car car1("Honda", "Black", "AE0085EP", eng1);
    cout << "Information about car:" << endl;
    car1.show();
    cout << "After reassign number and repaint:" << endl;
    car1.reassignNumber("AA9999BB");
    car1.repaint("Red");
    car1.show();

    return 0;
}
