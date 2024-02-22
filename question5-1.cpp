
#include <iostream>
#include <string>
using namespace std;

class automobile {
private:
    string manufacturerName;
    string modelName;
    int modelYear;

public:
    automobile(string manufacturer, string model, int year) {
        manufacturerName = manufacturer;
        modelName = model;
        modelYear = year;
    }

    string getManufacturerName() {
        return manufacturerName;
    }

    void setManufacturerName(string manufacturer) {
        manufacturerName = manufacturer;
    }

    string getModelName() {
        return modelName;
    }

    void setModelName(string model) {
        modelName = model;
    }

    int getModelYear() {
        return modelYear;
    }

    void setModelYear(int year) {
        modelYear = year;
    }
};

int main() {
    automobile myCar("BMW", "535i", 0);
    cout << "Manufacturer: " << myCar.getManufacturerName() << endl;
    cout << "Model: " << myCar.getModelName() << endl;
    myCar.setModelYear(2023);
    cout << "Model Year: " << myCar.getModelYear() << endl;

    return 0;
}
