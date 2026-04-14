#include "triangulo.h"
#include <cmath>
#include <sstream>

namespace {
double distancia(const Ponto& a, const Ponto& b) {
    double dx = a.get_x() - b.get_x();
    double dy = a.get_y() - b.get_y();
    return std::sqrt(dx * dx + dy * dy);
}
}

Triangulo::Triangulo(const Ponto& p1, const Ponto& p2, const Ponto& p3,
                     const Cor& preenchimento, const Cor& borda, double espessura)
    : Forma(preenchimento, borda, espessura), p1(p1), p2(p2), p3(p3) {}

double Triangulo::area() const {
    return std::abs((p1.get_x() * (p2.get_y() - p3.get_y()) +
                     p2.get_x() * (p3.get_y() - p1.get_y()) +
                     p3.get_x() * (p1.get_y() - p2.get_y())) / 2.0);
}

double Triangulo::perimetro() const {
    return distancia(p1, p2) + distancia(p2, p3) + distancia(p3, p1);
}

std::string Triangulo::to_svg() const {
    std::ostringstream oss;
    oss << "<polygon points=\""
        << p1.get_x() << ',' << p1.get_y() << ' '
        << p2.get_x() << ',' << p2.get_y() << ' '
        << p3.get_x() << ',' << p3.get_y()
        << "\" fill=\"" << cor_preenchimento.to_hex() << "\" stroke=\""
        << cor_borda.to_hex() << "\" stroke-width=\"" << espessura_borda << "\"/>";
    return oss.str();
}

std::string Triangulo::tipo() const { return "Triangulo"; }

void Triangulo::info() const {
    Forma::info();
    std::cout << "  Vertices: " << p1 << ", " << p2 << ", " << p3 << '\n';
}

void Triangulo::transladar(const Ponto& deslocamento) {
    p1 = p1 + deslocamento;
    p2 = p2 + deslocamento;
    p3 = p3 + deslocamento;
}
