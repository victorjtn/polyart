#include "linha.h"
#include <cmath>
#include <sstream>

namespace {
double comprimento(const Ponto& a, const Ponto& b) {
    double dx = a.get_x() - b.get_x();
    double dy = a.get_y() - b.get_y();
    return std::sqrt(dx * dx + dy * dy);
}
}

Linha::Linha(const Ponto& inicio, const Ponto& fim, const Cor& borda, double espessura)
    : Forma(Cor(0, 0, 0, 0), borda, espessura), inicio(inicio), fim(fim) {}

double Linha::area() const { return 0.0; }
double Linha::perimetro() const { return comprimento(inicio, fim); }

std::string Linha::to_svg() const {
    std::ostringstream oss;
    oss << "<line x1=\"" << inicio.get_x() << "\" y1=\"" << inicio.get_y()
        << "\" x2=\"" << fim.get_x() << "\" y2=\"" << fim.get_y()
        << "\" stroke=\"" << cor_borda.to_hex() << "\" stroke-width=\""
        << espessura_borda << "\"/>";
    return oss.str();
}

std::string Linha::tipo() const { return "Linha"; }

void Linha::info() const {
    Forma::info();
    std::cout << "  Inicio: " << inicio << " | Fim: " << fim << '\n';
}

void Linha::transladar(const Ponto& deslocamento) {
    inicio = inicio + deslocamento;
    fim = fim + deslocamento;
}
