#ifndef LINHA_H
#define LINHA_H

#include "forma.h"

class Linha : public Forma {
private:
    Ponto inicio;
    Ponto fim;

public:
    Linha(const Ponto& inicio, const Ponto& fim,
          const Cor& borda = Cor(0, 0, 0),
          double espessura = 1.0);

    double area() const override;
    double perimetro() const override;
    std::string to_svg() const override;
    std::string tipo() const override;
    void info() const override;
    void transladar(const Ponto& deslocamento) override;
};

#endif
