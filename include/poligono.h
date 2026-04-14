#ifndef POLIGONO_H
#define POLIGONO_H

#include <vector>
#include "forma.h"

class Poligono : public Forma {
private:
    std::vector<Ponto> vertices;

public:
    Poligono(const std::vector<Ponto>& vertices,
             const Cor& preenchimento = Cor(255, 255, 255),
             const Cor& borda = Cor(0, 0, 0),
             double espessura = 1.0);

    double area() const override;
    double perimetro() const override;
    std::string to_svg() const override;
    std::string tipo() const override;
    void info() const override;
    void transladar(const Ponto& deslocamento) override;

    const std::vector<Ponto>& get_vertices() const;
};

#endif
