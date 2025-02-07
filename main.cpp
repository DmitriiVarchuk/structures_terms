#include <iostream>
using namespace std;

struct Complex {
private:
    double* _real = nullptr;
    double* _imag = nullptr;

public:
    Complex(double real = 0.0, double imag = 0.0) {
        setReal(real);
        setImag(imag);
    }

    double getReal() const {
        return (_real == nullptr) ? 0.0 : *_real;
    }

    double getImag() const {
        return (_imag == nullptr) ? 0.0 : *_imag;
    }

    void setReal(double real) {
        if (_real != nullptr) {
            delete _real;
        }
        _real = new double{ real };
    }

    void setImag(double imag) {
        if (_imag != nullptr) {
            delete _imag;
        }
        _imag = new double{ imag };
    }

    ~Complex() {
        delete _real;
        delete _imag;
    }
};

Complex add(const Complex& a, const Complex& b) {
    return Complex(a.getReal() + b.getReal(), a.getImag() + b.getImag());
}

Complex subtract(const Complex& a, const Complex& b) {
    return Complex(a.getReal() - b.getReal(), a.getImag() - b.getImag());
}

Complex multiply(const Complex& a, const Complex& b) {
    double realPart = a.getReal() * b.getReal() - a.getImag() * b.getImag();
    double imagPart = a.getReal() * b.getImag() + a.getImag() * b.getReal();
    return Complex(realPart, imagPart);
}

Complex divide(const Complex& a, const Complex& b) {
    double denominator = b.getReal() * b.getReal() + b.getImag() * b.getImag();
    if (denominator == 0) {
        cout << "Division by zero is undefined. Returning the first complex number." << endl;
        return a;
    }
    double realPart = (a.getReal() * b.getReal() + a.getImag() * b.getImag()) / denominator;
    double imagPart = (a.getImag() * b.getReal() - a.getReal() * b.getImag()) / denominator;
    return Complex(realPart, imagPart);
}

void menu() {
    cout << "\nMenu:\n";
    cout << "1. Add complex numbers\n";
    cout << "2. Subtract complex numbers\n";
    cout << "3. Multiply complex numbers\n";
    cout << "4. Divide complex numbers\n";
    cout << "5. Exit\n";
}

int main() {
    Complex a(3.0, 4.0);
    Complex b(1.0, 2.0);

    cout << "First complex number: " << a.getReal() << " + " << a.getImag() << "i" << endl;
    cout << "Second complex number: " << b.getReal() << " + " << b.getImag() << "i" << endl;

    while (true) {
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Sum: ";
            cout << add(a, b).getReal() << " + " << add(a, b).getImag() << "i" << endl;
            break;
        case 2:
            cout << "Difference: ";
            cout << subtract(a, b).getReal() << " + " << subtract(a, b).getImag() << "i" << endl;
            break;
        case 3:
            cout << "Product: ";
            cout << multiply(a, b).getReal() << " + " << multiply(a, b).getImag() << "i" << endl;
            break;
        case 4:
            cout << "Quotient: ";
            cout << divide(a, b).getReal() << " + " << divide(a, b).getImag() << "i" << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}