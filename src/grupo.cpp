#include "grupo.h"
#include <iostream>
#include <numeric>
#include <sstream>

Grupo::Grupo(const Cor& preenchimento, const Cor& borda, double espessura)
    : Forma(preenchimento, borda, espessura) {}

Grupo::~Grupo() {
    for (Forma* forma : formas) {
        delete forma;
    }
}

double Grupo::area() const {
    return std::accumulate(formas.begin(), formas.end(), 0.0,
        [](double acc, Forma* forma) { return acc + forma->area(); });
}

double Grupo::perimetro() const {
    return std::accumulate(formas.begin(), formas.end(), 0.0,
        [](double acc, Forma* forma) { return acc + forma->perimetro(); });
}

std::string Grupo::to_svg() const {
    std::ostringstream oss;
    oss << "<g>\n";
    for (const Forma* forma : formas) {
        oss << "  " << forma->to_svg() << "\n";
    }
    oss << "</g>";
    return oss.str();
}

std::string Grupo::tipo() const { return "Grupo"; }

void Grupo::info() const {
    Forma::info();
    std::cout << "  Formas internas: " << formas.size() << '\n';
}

void Grupo::transladar(const Ponto& deslocamento) {
    for (Forma* forma : formas) {
        forma->transladar(deslocamento);
    }
}

void Grupo::adicionar(Forma* forma) {
    if (forma != nullptr) formas.push_back(forma);
}

void Grupo::remover(int indice) {
    if (indice >= 0 && indice < static_cast<int>(formas.size())) {
        delete formas[indice];
        formas.erase(formas.begin() + indice);
    }
}

void Grupo::listar() const {
    for (size_t i = 0; i < formas.size(); ++i) {
        std::cout << "[" << i << "] ";
        formas[i]->info();
    }
}

std::vector<Forma*>& Grupo::get_formas() { return formas; }
