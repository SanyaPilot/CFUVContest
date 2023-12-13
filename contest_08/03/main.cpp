#include <iostream>

// Начало вставленного кода
class IntSharedPointer {
private:
    int* refs;
    int* p;
    void decreaseRefs() {
        (*refs)--;
        if (*refs == 0) {
            delete p;
            delete refs;
        }
    }
    void copyRefs(const IntSharedPointer& b) {
        p = b.p;
        refs = b.refs;
        (*refs)++;
    }
public:
    IntSharedPointer(int* pointer) {
        refs = new int{1};
        p = pointer;
    }
    IntSharedPointer(IntSharedPointer& b) {
        copyRefs(b);
    }
    ~IntSharedPointer() {
        decreaseRefs();
    }
    int& operator*() {
        return *p;
    }
    IntSharedPointer& operator=(const IntSharedPointer& b) {
        if (this == &b) {
            return *this;
        }
        decreaseRefs();
        copyRefs(b);
        return *this;
    }
};
// Конец вставленного кода

void print(IntSharedPointer p){
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p){
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main(){
    IntSharedPointer p(new int);
    std::cin >> *p;
    p = p;
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);
    
    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);
    
    p = p2;
    try{
        print_with_exception(p);
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}
