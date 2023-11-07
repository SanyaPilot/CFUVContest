#include <iostream>
#include <deque>

// Начало вставленного кода
class Water {
    public:
    Water(double init_temp) {
        temp = init_temp;
    }

    double get_temp() {
        return temp;
    }

    private:
    double temp;
};

class Teapot {
    public:
    Teapot(Water water) {
        temp = water.get_temp();
    }

    bool is_boiling() {
        return temp >= 100;
    }

    void heat_up(double add_temp) {
        temp += add_temp;
    }

    private:
    double temp;
};
// Конец вставленного кода

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for(auto& t : heat) std::cin >> t;
    
    Water water(temperature);
    Teapot teapot(water);
    
    while(not teapot.is_boiling()){
        teapot.heat_up(heat.front());
        heat.pop_front();
    }
    
    for(auto t : heat) std::cout << t << ' ';
}
