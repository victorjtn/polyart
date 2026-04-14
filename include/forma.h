#ifndef FORMA_H
#define FORMA_H

#include <string>
#include "cor.h"
#include "ponto.h"

class Forma {
protected:
    Cor cor_preenchimento;
    Cor cor_borda;
    double espessura_borda;

public:
    Forma(const Cor& preenchimento = Cor(255, 255, 255),
          const Cor& borda = Cor(0, 0, 0),
          double espessura = 1.0);

    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual std::string to_svg() const = 0;
    virtual std::string tipo() const = 0;
    virtual void info() const;
    virtual void transladar(const Ponto& deslocamento) = 0;
    virtual ~Forma();

    Cor get_cor_preenchimento() const;
    Cor get_cor_borda() const;
    double get_espessura_borda() const;

    void set_cor_preenchimento(const Cor& cor);
    void set_cor_borda(const Cor& cor);
    void set_espessura_borda(double espessura);
};

#endif
