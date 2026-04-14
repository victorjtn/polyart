#include "cor.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace {
int limitar_cor(int valor) {
    if (valor < 0) return 0;
    if (valor > 255) return 255;
    return valor;
}
}

Cor::Cor(int r, int g, int b, int alfa)
    : r(limitar_cor(r)), g(limitar_cor(g)), b(limitar_cor(b)), alfa(limitar_cor(alfa)) {}

int Cor::get_r() const { return r; }
int Cor::get_g() const { return g; }
int Cor::get_b() const { return b; }
int Cor::get_alfa() const { return alfa; }

std::string Cor::to_hex() const {
    std::ostringstream oss;
    oss << '#'
        << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << r
        << std::setw(2) << std::setfill('0') << g
        << std::setw(2) << std::setfill('0') << b;
    return oss.str();
}

std::string Cor::to_rgba() const {
    std::ostringstream oss;
    oss << "rgba(" << r << ',' << g << ',' << b << ',' << alfa << ')';
    return oss.str();
}

bool Cor::operator==(const Cor& outra) const {
    return r == outra.r && g == outra.g && b == outra.b && alfa == outra.alfa;
}

std::ostream& operator<<(std::ostream& os, const Cor& cor) {
    os << cor.to_rgba() << " [" << cor.to_hex() << ']';
    return os;
}
