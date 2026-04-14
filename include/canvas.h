#ifndef CANVAS_H
#define CANVAS_H

#include <map>
#include <string>
#include <vector>
#include "camada.h"
#include "forma.h"

class Canvas {
private:
    int largura;
    int altura;
    Cor cor_fundo;
    std::map<std::string, Camada<Forma>> camadas;
    std::string camada_ativa;

    static Canvas* instancia;
    Canvas(int largura = 800, int altura = 600, const Cor& fundo = Cor(255, 255, 255));

public:
    static int total_formas;

    Canvas(const Canvas&) = delete;
    Canvas& operator=(const Canvas&) = delete;

    static Canvas& get_instancia();
    ~Canvas();

    void criar_camada(const std::string& nome);
    void remover_camada(const std::string& nome);
    void listar_camadas() const;
    void definir_camada_ativa(const std::string& nome);
    std::string get_camada_ativa() const;

    void adicionar_forma(Forma* forma, const std::string& nome_camada = "");
    void remover_forma(const std::string& nome_camada, int indice);
    void listar_formas_camada(const std::string& nome_camada) const;
    std::vector<Forma*> get_todas_formas() const;
    Camada<Forma>* obter_camada(const std::string& nome);
    const std::map<std::string, Camada<Forma>>& get_camadas() const;

    void exportar_svg(const std::string& arquivo) const;

    int get_largura() const;
    int get_altura() const;
    Cor get_cor_fundo() const;
    void set_tamanho(int nova_largura, int nova_altura);
    void set_cor_fundo(const Cor& cor);
};

#endif