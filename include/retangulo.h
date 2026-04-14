#ifndef RETANGULO_H
#define RETANGULO_H

#include "forma.h"

class Retangulo : public Forma {
private:
    Ponto origem;
    double largura;
    double altura;

public:
    Retangulo(const Ponto& origem, double largura, double altura,
              const Cor& preenchimento = Cor(255, 255, 255),
              const Cor& borda = Cor(0, 0, 0),
              double espessura = 1.0);

    double area() const override;
    double perimetro() const override;
    std::string to_svg() const override;
    std::string tipo() const override;
    void info() const override;
    void transladar(const Ponto& deslocamento) override;

    Ponto get_origem() const;
    double get_largura() const;
    double get_altura() const;
};

#endif
