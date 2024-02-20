#include <iostream>

using namespace std;

float add(float x, float y);
float subtract(float x, float y);
float multiply(float x, float y);
float divide(float x, float y);

void calculator() {
    cout << "Select operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;

    cout << "Enter choice (1/2/3/4): ";
    char choice;
    cin >> choice;

    if (choice == '1' || choice == '2' || choice == '3' || choice == '4') {
        cout << "Enter first number: ";
        float num1;
        cin >> num1;

        cout << "Enter second number: ";
        float num2;
        cin >> num2;

        switch (choice) {
            case '1':
                cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                break;
            case '2':
                cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                break;
            case '3':
                cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                break;
            case '4':
                if (num2 != 0) {
                    cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                } else {
                    cout << "Error: Cannot divide by zero" << endl;
                }
                break;
        }
    } else {
        cout << "Invalid choice. Please enter a valid number (1/2/3/4)" << endl;
    }
}

float add(float x, float y) {
    return x + y;
}

float subtract(float x, float y) {
    return x - y;
}

float multiply(float x, float y) {
    return x * y;
}

float divide(float x, float y) {
    return x / y;
}

int main() {
    calculator();
    return 0;
}