#include <iostream>

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

// Начало вставленного кода
#include <sstream>
#include <numeric>
#include <complex>

Complex make_complex(std::string input) {
    std::stringstream ss(input);
    Complex result;
    ss >> result.re;
    
    std::string im_str;
    ss >> im_str;
    if (im_str.length() == 1) {
        // Read one more time
        std::string temp;
        ss >> temp;
        im_str += temp;
    }
    
    result.im = std::stod(im_str);

    // -0 check
    if (result.re == -0) result.re = 0;
    if (result.im == -0) result.im = 0;
    return result;
}

void print(Complex num) {
    std::string im_str = "";

    // -0 check
    if (num.re == -0) num.re = 0;
    if (num.im == -0) num.im = 0;

    if (num.im >= 0) im_str += "+";

    im_str += std::to_string(num.im);
    im_str.erase ( im_str.find_last_not_of('0') + 1, std::string::npos );
    im_str.erase ( im_str.find_last_not_of('.') + 1, std::string::npos );

    std::cout << num.re << im_str << "j\n";
}

Complex sum(Complex a, Complex b) {
    std::complex<double> c1 = std::complex<double>(a.re, a.im);
    std::complex<double> c2 = std::complex<double>(b.re, b.im);
    std::complex<double> c_res = c1 + c2;
    Complex res;
    res.re = c_res.real();
    res.im = c_res.imag();
    return res;
}

Complex sub(Complex a, Complex b) {
    std::complex<double> c1 = std::complex<double>(a.re, a.im);
    std::complex<double> c2 = std::complex<double>(b.re, b.im);
    std::complex<double> c_res = c1 - c2;
    Complex res;
    res.re = c_res.real();
    res.im = c_res.imag();
    return res;
}

Complex mul(Complex a, Complex b) {
    std::complex<double> c1 = std::complex<double>(a.re, a.im);
    std::complex<double> c2 = std::complex<double>(b.re, b.im);
    std::complex<double> c_res = c1 * c2;
    Complex res;
    res.re = c_res.real();
    res.im = c_res.imag();
    return res;
}

Complex div(Complex a, Complex b) {
    std::complex<double> c1 = std::complex<double>(a.re, a.im);
    std::complex<double> c2 = std::complex<double>(b.re, b.im);
    std::complex<double> c_res = c1 / c2;
    Complex res;
    res.re = c_res.real();
    res.im = c_res.imag();
    return res;
}
// Конец

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
