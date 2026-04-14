#include "poligono.h"
#include <cmath>
#include <sstream>

namespace {
double dist(const Ponto& a, const Ponto& b) {
    double dx = a.get_x() - b.get_x();
    double dy = a.get_y() - b.get_y();
    return std::sqrt(dx * dx + dy * dy);
}
}

Poligono::Poligono(const std::vector<Ponto>& vertices, const Cor& preenchimento,
                   const Cor& borda, double espessura)
    : Forma(preenchimento, borda, espessura), vertices(vertices) {}

double Poligono::area() const {
    if (vertices.size() < 3) return 0.0;
    double soma = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        const Ponto& atual = vertices[i];
        const Ponto& prox = vertices[(i + 1) % vertices.size()];
        soma += atual.get_x() * prox.get_y() - prox.get_x() * atual.get_y();
    }
    return std::abs(soma) / 2.0;
}

double Poligono::perimetro() const {
    if (vertices.size() < 2) return 0.0;
    double soma = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        soma += dist(vertices[i], vertices[(i + 1) % vertices.size()]);
    }
    return soma;
}

std::string Poligono::to_svg() const {
    std::ostringstream pontos;
    for (size_t i = 0; i < vertices.size(); ++i) {
        pontos << vertices[i].get_x() << ',' << vertices[i].get_y();
        if (i + 1 < vertices.size()) pontos << ' ';
    }

    std::ostringstream oss;
    oss << "<polygon points=\"" << pontos.str() << "\" fill=\""
        << cor_preenchimento.to_hex() << "\" stroke=\"" << cor_borda.to_hex()
        << "\" stroke-width=\"" << espessura_borda << "\"/>";
    return oss.str();
}

std::string Poligono::tipo() const { return "Poligono"; }

void Poligono::info() const {
    Forma::info();
    std::cout << "  Quantidade de vertices: " << vertices.size() << '\n';
}

void Poligono::transladar(const Ponto& deslocamento) {
    for (Ponto& v : vertices) {
        v = v + deslocamento;
    }
}

const std::vector<Ponto>& Poligono::get_vertices() const { return vertices; }
