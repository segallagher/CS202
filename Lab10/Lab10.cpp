#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct obj {
    obj() { cout << "Constructed" << endl; }
    ~obj() { cout << "Destructed" << endl; }
};

void functionC() {
    throw std::runtime_error("functionC() threw std::runtime_error");
}

void functionB() {
    obj b;
    cout << "Starting functionB()" << endl;
    functionC();
    cout << "Ending functionB()" << endl;
}

void functionA() {
    try {
        functionB();
        // your code here
    }
    catch(const std::runtime_error& e){
        cout << "Caught an exception: " << e.what() << endl;
        // your code here
    }
}
int main() {
    cout << "Starting main()" << endl;
    functionA();
    cout << "Ended normally." << endl;
    return 0;
}