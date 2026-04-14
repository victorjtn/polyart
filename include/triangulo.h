#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "forma.h"

class Triangulo : public Forma {
private:
    Ponto p1;
    Ponto p2;
    Ponto p3;

public:
    Triangulo(const Ponto& p1, const Ponto& p2, const Ponto& p3,
              const Cor& preenchimento = Cor(255, 255, 255),
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
