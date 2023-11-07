#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Начало вставленного кода
#include <cmath>

class Point {
    public:
        Point(double start_x, double start_y) {
            x = start_x;
            y = start_y;
            update_pol();
        }

        double get_x() const {
            return x;
        }
        void set_x(double n) {
            x = n;
            update_pol();
        }

        double get_y() const {
            return y;
        }
        void set_y(double n) {
            y = n;
            update_pol();
        }

        double get_r() const {
            return r;
        }
        void set_r(double n) {
            r = n;
            update_cart();
        }

        double get_a() const {
            return a;
        }
        void set_a(double n) {
            a = n;
            update_cart();
        }
    
    private:
        double x, y, r, a;
        void update_cart() {
            x = r * cos(a);
            y = r * sin(a);
        }
        void update_pol() {
            r = sqrt(pow(x, 2) + pow(y, 2));
            if (r == 0) {
                a = 0;
                return;
            }

            if (x > 0) {
                a = atan(y / x);
                if (y < 0) {
                    a += 2 * M_PI;
                }
            } else if (x < 0) {
                a = atan(y / x) + M_PI;
            } else {
                if (y > 0) {
                    a = M_PI_2;
                } else {
                    a = 3 * M_PI_2;
                }
            }
        }
};
// Конец вставленного кода

int main(){
    double x, y;
    std::cin >> x >> y;

    Point p(x, y);
    json moves;
    std::cin >> moves;
    
    for(auto& move : moves){
        std::string ort = move["ort"];
        double value = move["value"];
        if (ort == "x") p.set_x(p.get_x() + value);
        else if (ort == "y") p.set_y(p.get_y() + value);
        else if (ort == "r") p.set_r(p.get_r() + value);
        else p.set_a(p.get_a() + value);
        std::cout << round(p.get_x()*(1E+5))/(1E+5) << ' ' << round(p.get_y()*(1E+5))/(1E+5) << std::endl;    
    }
}