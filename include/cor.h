#ifndef COR_H
#define COR_H

#include <iostream>
#include <string>

class Cor {
private:
    int r;
    int g;
    int b;
    int alfa;

public:
    Cor(int r = 0, int g = 0, int b = 0, int alfa = 255);

    int get_r() const;
    int get_g() const;
    int get_b() const;
    int get_alfa() const;

    std::string to_hex() const;
    std::string to_rgba() const;

    bool operator==(const Cor& outra) const;

    friend std::ostream& operator<<(std::ostream& os, const Cor& cor);
};

#endif
