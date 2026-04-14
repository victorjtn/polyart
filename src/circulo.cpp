#include "circulo.h"
#include <cmath>
#include <sstream>

namespace { constexpr double PI = 3.14159265358979323846; }

Circulo::Circulo(const Ponto& centro, double raio, const Cor& preenchimento,
                 const Cor& borda, double espessura)
    : Forma(preenchimento, borda, espessura), centro(centro), raio(raio) {}

double Circulo::area() const { return PI * raio * raio; }
double Circulo::perimetro() const { return 2.0 * PI * raio; }

std::string Circulo::to_svg() const {
    std::ostringstream oss;
    oss << "<circle cx=\"" << centro.get_x() << "\" cy=\"" << centro.get_y()
        << "\" r=\"" << raio << "\" fill=\"" << cor_preenchimento.to_hex()
        << "\" stroke=\"" << cor_borda.to_hex() << "\" stroke-width=\""
        << espessura_borda << "\"/>";
    return oss.str();
}

std::string Circulo::tipo() const { return "Circulo"; }

void Circulo::info() const {
    Forma::info();
    std::cout << "  Centro: " << centro << " | Raio: " << raio << '\n';
}

void Circulo::transladar(const Ponto& deslocamento) { centro = centro + deslocamento; }
Ponto Circulo::get_centro() const { return centro; }
double Circulo::get_raio() const { return raio; }
