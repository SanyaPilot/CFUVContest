#include <iostream>

class Cat {
    public:
        Cat(bool status) {
            alive = status;
        }

        bool is_alive() {
            return alive;
        }
    private:
        bool alive;
};

class Box {
    public:
        Cat open() {
            return Cat(rand() > (RAND_MAX / 2));
        }
};

int main() {
    Box box;
    Cat cat = box.open();
    if (cat.is_alive()) {
        std::cout << "alive";
    } else {
        std::cout << "dead";
    }
    return 0;
}