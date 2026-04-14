#include "ponto.h"

Ponto::Ponto(double x, double y) : x(x), y(y) {}

double Ponto::get_x() const { return x; }
double Ponto::get_y() const { return y; }

Ponto Ponto::operator+(const Ponto& outro) const {
    return Ponto(x + outro.x, y + outro.y);
}

Ponto Ponto::operator-(const Ponto& outro) const {
    return Ponto(x - outro.x, y - outro.y);
}

Ponto Ponto::operator*(double escalar) const {
    return Ponto(x * escalar, y * escalar);
}

bool Ponto::operator==(const Ponto& outro) const {
    return x == outro.x && y == outro.y;
}

bool Ponto::operator!=(const Ponto& outro) const {
    return !(*this == outro);
}

std::ostream& operator<<(std::ostream& os, const Ponto& ponto) {
    os << "(" << ponto.x << ", " << ponto.y << ")";
    return os;
}
