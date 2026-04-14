#ifndef GRUPO_H
#define GRUPO_H

#include <vector>
#include "forma.h"

class Grupo : public Forma {
private:
    std::vector<Forma*> formas;

public:
    Grupo(const Cor& preenchimento = Cor(255, 255, 255),
          const Cor& borda = Cor(0, 0, 0),
          double espessura = 1.0);

    ~Grupo() override;

    double area() const override;
    double perimetro() const override;
    std::string to_svg() const override;
    std::string tipo() const override;
    void info() const override;
    void transladar(const Ponto& deslocamento) override;

    void adicionar(Forma* forma);
    void remover(int indice);
    void listar() const;
    std::vector<Forma*>& get_formas();
};

#endif
