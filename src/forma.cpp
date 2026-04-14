#include "forma.h"
#include "canvas.h"
#include <iostream>

Forma::Forma(const Cor& preenchimento, const Cor& borda, double espessura)
    : cor_preenchimento(preenchimento), cor_borda(borda), espessura_borda(espessura) {
    ++Canvas::total_formas;
}

Forma::~Forma() = default;

void Forma::info() const {
    std::cout << "Tipo: " << tipo()
              << " | Area: " << area()
              << " | Perimetro: " << perimetro()
              << " | Preenchimento: " << cor_preenchimento
              << " | Borda: " << cor_borda
              << " | Espessura: " << espessura_borda
              << '\n';
}

Cor Forma::get_cor_preenchimento() const { return cor_preenchimento; }
Cor Forma::get_cor_borda() const { return cor_borda; }
double Forma::get_espessura_borda() const { return espessura_borda; }

void Forma::set_cor_preenchimento(const Cor& cor) { cor_preenchimento = cor; }
void Forma::set_cor_borda(const Cor& cor) { cor_borda = cor; }
void Forma::set_espessura_borda(double espessura) { espessura_borda = espessura; }
