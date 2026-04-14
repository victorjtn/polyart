#ifndef PONTO_H
#define PONTO_H

#include <iostream>

class Ponto {
private:
    double x;
    double y;

public:
    Ponto(double x = 0.0, double y = 0.0);

    double get_x() const;
    double get_y() const;

    Ponto operator+(const Ponto& outro) const;
    Ponto operator-(const Ponto& outro) const;
    Ponto operator*(double escalar) const;
    bool operator==(const Ponto& outro) const;
    bool operator!=(const Ponto& outro) const;

    friend std::ostream& operator<<(std::ostream& os, const Ponto& ponto);
};

#endif
