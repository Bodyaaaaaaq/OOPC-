#include <iostream>
using namespace std;

template <typename T>
class CheckSum {
public:
    static int get(T value) {
      unsigned char* bytes = (unsigned char*) &value;
        int sumbits = 0;

        for (int i = 0; i < sizeof(T); i++) {
         unsigned char b = bytes[i];
            while (b) {
                sumbits += b & 1;
                b >>= 1;
            }
        }
        return sumbits;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    cout << "Enter int number: ";
    int a;
    float c;
    cin >> a;
    cout << "Enter float number: ";
    cin >> c;

    cout << "Hash int: " << CheckSum<int>::get(a) << endl;
    cout << "Hash double: " << CheckSum<float>::get(c) << endl;

    return 0;
}
