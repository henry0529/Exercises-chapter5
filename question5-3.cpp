#include <iostream>
#include <cstring> 
using namespace std;

class lengthString {
private:
    char * str; 

public:
    lengthString() : str(nullptr) {}
    lengthString(const char * s) : str(nullptr) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    lengthString(const lengthString & other) : str(nullptr) {
        if (other.str) {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
    }
    ~lengthString() {
        delete[] str;
    }

    lengthString& operator=(const lengthString& other) {
        if (this != &other) { 
            delete[] str;
            if (other.str) {
                str = new char[strlen(other.str) + 1];
                strcpy(str, other.str);
            }
        }
        return *this;
    }

    void append(const lengthString& other) {
        if (other.str) {
            char* temp = new char[size() + other.size() + 1];
            strcpy(temp, str);
            strcat(temp, other.str);
            delete[] str;
            str = temp;
        }
    }

    void concatenate(const lengthString& other) {
        append(other);
    }

    char characterAt(int index) const {
        if (str && index >= 0 && index < size()) {
            return str[index];
        }
        throw out_of_range("Index not in range");
    }

    int size() const {
        return str ? strlen(str) : 0;
    }

    const char* c_str() const {
        return str ? str : "";
    }
};

int main() {
    lengthString str1("Hello ");
    lengthString str2("world");

    str1.concatenate(str2);
    cout << "Concatenated String: " << str1.c_str() << endl;
    cout << "Character at index 4: " << str1.characterAt(4) << endl;

    return 0;
}




