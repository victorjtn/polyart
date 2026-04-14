#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma.h"

class Circulo : public Forma {
private:
    Ponto centro;
    double raio;

public:
    Circulo(const Ponto& centro, double raio,
            const Cor& preenchimento = Cor(255, 255, 255),
            const Cor& borda = Cor(0, 0, 0),
            double espessura = 1.0);

    double area() const override;
    double perimetro() const override;
    std::string to_svg() const override;
    std::string tipo() const override;
    void info() const override;
    void transladar(const Ponto& deslocamento) override;

    Ponto get_centro() const;
    double get_raio() const;
};

#endif
