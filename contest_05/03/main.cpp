#include <iostream>
#include <string>

// Начало вставленного кода
#include <complex.h>

class Complex {
    public:
        Complex(std::string input) {
            double re, im;
            std::stringstream ss(input);
            ss >> re;
            
            std::string im_str;
            ss >> im_str;
            if (im_str.length() == 1) {
                // Read one more time
                std::string temp;
                ss >> temp;
                im_str += temp;
            }
            
            im = std::stod(im_str);

            // -0 check
            if (re == -0) re = 0;
            if (im == -0) im = 0;

            num = std::complex<double>(re, im);
        }

        Complex(std::complex<double> init_num) {
            num = init_num;
        }

        double re() const {
            return num.real();
        }
        double im() const {
            return num.imag();
        }

        Complex operator+(const Complex &b) {
            return Complex(num + b.num);
        }
        Complex operator-(const Complex &b) {
            return Complex(num - b.num);
        }
        Complex operator*(const Complex &b) {
            return Complex(num * b.num);
        }
        Complex operator/(const Complex &b) {
            return Complex(num / b.num);
        }

        friend std::ostream& operator<<(std::ostream& out, const Complex& num){
            double re = num.re();
            double im = num.im();
            out << (re == 0.0 ? 0.0 : re)
                << (im < 0 ? "":"+")
                << (im == 0.0 ? 0.0 : im) << 'j';
            return out;
        }
    
    private:
        std::complex<double> num;
};
// Конец вставленного кода

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2(num);
    
    std::cout << c1+c2 << '\n' << c1-c2 << '\n'
              << c1*c2 << '\n' << c1/c2 << std::endl;
}
