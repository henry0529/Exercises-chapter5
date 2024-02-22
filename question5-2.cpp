#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Automobile {
private:
    string manufacturerName;
    string modelName;
    int modelYear;

public:
    Automobile(string manufacturer, string model, int year) {
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

    string getDescription() {
        return to_string(modelYear) + " " + manufacturerName + " " + modelName;
    }

    int getAge() {
        time_t t = time(0);   
        struct tm* now = localtime(&t);
        return (now->tm_year + 1900) - modelYear;
    }
};

int main() {
    Automobile myCar("Chevrolet", "Impala", 1957);
    cout << "Description of automobile: " << myCar.getDescription() << endl;
    cout << "Age of automobile: " << myCar.getAge() << " years" << endl;

    return 0;
}
