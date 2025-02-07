#include <iostream>
using namespace std;

struct fraction {
public:
    int numerator;
    int denominator;
    int integer;
    bool isIncorrect;

    void simplify() {
        if (numerator >= denominator) {
            integer = numerator / denominator;
            numerator = numerator % denominator;
        }
    }

    void reduce() {
        if (numerator > denominator) {
            for (int i = denominator; i > 0; i--) {
                if (numerator % i == 0 && denominator % i == 0) {
                    numerator = numerator / i;
                    denominator = denominator / i;
                }
            }
        }
    }

    void plus(fraction f) {
        if (&f != nullptr) {
            if (denominator == f.denominator) {
                numerator = numerator + f.numerator;
            }
            else {
                numerator = numerator * f.denominator + f.numerator * denominator;
                denominator = denominator * f.denominator;
            }
            reduce();
        }

    }

    void minus(fraction f) {
        if (&f != nullptr) {
            if (denominator == f.denominator) {
                numerator = numerator - f.numerator;
            }
            else {
                numerator = numerator * f.denominator - f.numerator * denominator;
                denominator = denominator * f.denominator;
            }
            reduce();
        }

    }

    void multiply(fraction f) {
        if (&f != nullptr) {
            numerator = numerator * f.numerator;
            denominator = denominator * f.denominator;
            reduce();
        }

    }

    void divide(fraction f) {
        if (&f != nullptr) {
            numerator = numerator * f.denominator;
            denominator = denominator * f.numerator;
            reduce();
        }

    }
};

int main() {
    fraction f1, f2, result;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add fractions\n";
        cout << "2. Subtract fractions\n";
        cout << "3. Multiply fractions\n";
        cout << "4. Divide fractions\n";
        cout << "5. Simplify fraction\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {

            cout << "Enter second fraction (numerator denominator): ";
            cin >> f2.numerator >> f2.denominator;
        }
        else if (choice == 5) {
            cout << "Enter fraction to simplify (numerator denominator): ";
            cin >> f1.numerator >> f1.denominator;
        }

        switch (choice) {
        case 1:
            result = f1;
            result.plus(f2);
            cout << "Result: " << result.numerator << "/" << result.denominator << "\n";
            break;
        case 2:
            result = f1;
            result.minus(f2);
            cout << "Result: " << result.numerator << "/" << result.denominator << "\n";
            break;
        case 3:
            result = f1;
            result.multiply(f2);
            cout << "Result: " << result.numerator << "/" << result.denominator << "\n";
            break;
        case 4:
            result = f1;
            result.divide(f2);
            cout << "Result: " << result.numerator << "/" << result.denominator << "\n";
            break;
        case 5:
            f1.simplify();
            cout << "Simplified fraction: " << f1.integer << " " << f1.numerator << "/" << f1.denominator << "\n";
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}