#include <iostream>

class Keeper{
    int trash;
    int secret;
    
public:
    Keeper(){
        std::cin >> secret;
    }
};

// Начало вставленного кода
struct Hack {
    int trash;
    int secret;
};
int hack_it(Keeper keeper) {
    Hack* h = reinterpret_cast<Hack*>(&keeper);
    return h->secret;
}
// Конец вставленного кода

int main(){
    Keeper keeper;
    int secret= hack_it(keeper);
    std::cout << secret;
}
