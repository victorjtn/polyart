#include "retangulo.h"
#include <sstream>

Retangulo::Retangulo(const Ponto& origem, double largura, double altura,
                     const Cor& preenchimento, const Cor& borda, double espessura)
    : Forma(preenchimento, borda, espessura), origem(origem), largura(largura), altura(altura) {}

double Retangulo::area() const { return largura * altura; }
double Retangulo::perimetro() const { return 2.0 * (largura + altura); }

std::string Retangulo::to_svg() const {
    std::ostringstream oss;
    oss << "<rect x=\"" << origem.get_x() << "\" y=\"" << origem.get_y()
        << "\" width=\"" << largura << "\" height=\"" << altura
        << "\" fill=\"" << cor_preenchimento.to_hex() << "\" stroke=\""
        << cor_borda.to_hex() << "\" stroke-width=\"" << espessura_borda << "\"/>";
    return oss.str();
}

std::string Retangulo::tipo() const { return "Retangulo"; }

void Retangulo::info() const {
    Forma::info();
    std::cout << "  Origem: " << origem << " | Largura: " << largura
              << " | Altura: " << altura << '\n';
}

void Retangulo::transladar(const Ponto& deslocamento) { origem = origem + deslocamento; }
Ponto Retangulo::get_origem() const { return origem; }
double Retangulo::get_largura() const { return largura; }
double Retangulo::get_altura() const { return altura; }
