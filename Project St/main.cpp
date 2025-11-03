#include <iostream>
class T {
    int x;
public:
    T(int _x = 0) : x(_x) {
        std::cerr << "T(int " << x << ")\n";
    }
    T(const T& t) : x(t.x) {
        std::cerr << "T(const &T " << x << ")\n";
    }
    ~T() {
        std::cerr << "~T(" << x << ")\n";
    }
    const T& operator=(const T& t) {
        if (this != &t) {
            this->~T();
            new (this) T(t);
        }
        return *this;
    }
    friend class C;
};

class C {
    T x;
public:
    C(T _x = 0) : x(_x) {
        std::cerr << "C(T " << x.x << ")\n";
    }
    C(const C& c) : x(c.x) {
        std::cerr << "C(const &C " << x.x << ")\n";
    }
    ~C() {
        std::cerr << "~C(" << x.x << ")\n";
    }
};

int main()
{
    std::cerr << __LINE__ << '\n';
    T a(1), b(2);
    std::cerr << __LINE__ << '\n';
    C x(a), y(b);
    std::cerr << __LINE__ << '\n';
    a = b;
    std::cerr << __LINE__ << '\n';
    x = y;
    std::cerr << __LINE__ << '\n';
}
