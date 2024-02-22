#include <iostream>
#include <cstring>

class studentCollection {
private:
    struct studentRecord {
        int studentNumber;
        int grade;
    };

    studentRecord* records;
    int numRecords;
    int capacity;

public:
    studentCollection() : records(nullptr), numRecords(0), capacity(0) {}
    studentCollection(const studentCollection& other) : records(nullptr), numRecords(0), capacity(0) {
        copyFrom(other);
    }

    studentCollection& operator=(const studentCollection& other) {
        if (this != &other) {
            delete[] records;
            records = nullptr;
            numRecords = 0;
            capacity = 0;
            copyFrom(other);
        }
        return *this;
    }

    ~studentCollection() {
        delete[] records;
    }

    void addRecord(int stuNum, int gr) {
        if (numRecords == capacity) {
            expandCapacity();
        }
        records[numRecords].studentNumber = stuNum;
        records[numRecords].grade = gr;
        numRecords++;
    }

    double averageRecord() const {
        if (numRecords == 0) {
            return 0.0;
        }

        double total = 0.0;
        for (int i = 0; i < numRecords; i++) {
            total += records[i].grade;
        }
        return total / numRecords;
    }

    studentCollection RecordsWithinRange(int lowGrade, int highGrade) const {
        studentCollection result;
        for (int i = 0; i < numRecords; i++) {
            if (records[i].grade >= lowGrade && records[i].grade <= highGrade) {
                result.addRecord(records[i].studentNumber, records[i].grade);
            }
        }
        return result;
    }

private:
    void copyFrom(const studentCollection& other) {
        capacity = other.capacity;
        numRecords = other.numRecords;
        records = new studentRecord[capacity];
        for (int i = 0; i < numRecords; i++) {
            records[i] = other.records[i];
        }
    }

    void expandCapacity() {
        int newCapacity = capacity + 5;
        studentRecord* newRecords = new studentRecord[newCapacity];
        for (int i = 0; i < numRecords; i++) {
            newRecords[i] = records[i];
        }
        delete[] records;
        records = newRecords;
        capacity = newCapacity;
    }
};

int main() {
    studentCollection sc;
    sc.addRecord(1274, 91);
    sc.addRecord(1275, 80);
    sc.addRecord(1276, 60);
  

    studentCollection result = sc.RecordsWithinRange(80, 90);
    double avg = result.averageRecord();
    std::cout << "Average grade in range: " << avg << std::endl;

    return 0;
}
