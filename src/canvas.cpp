#include "canvas.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

Canvas* Canvas::instancia = nullptr;
int Canvas::total_formas = 0;

Canvas::Canvas(int largura, int altura, const Cor& fundo)
    : largura(largura), altura(altura), cor_fundo(fundo), camada_ativa("principal") {
    criar_camada("principal");
}

Canvas& Canvas::get_instancia() {
    if (instancia == nullptr) {
        instancia = new Canvas();
    }
    return *instancia;
}

Canvas::~Canvas() {
    for (auto& par : camadas) {
        for (Forma* forma : par.second.get_elementos()) {
            delete forma;
        }
    }
    instancia = nullptr;
}

void Canvas::criar_camada(const std::string& nome) {
    if (camadas.find(nome) == camadas.end()) {
        camadas.emplace(nome, Camada<Forma>(nome));
    }
}

void Canvas::remover_camada(const std::string& nome) {
    auto it = camadas.find(nome);
    if (it != camadas.end()) {
        for (Forma* forma : it->second.get_elementos()) {
            delete forma;
        }
        camadas.erase(it);
        if (camada_ativa == nome) {
            camada_ativa = camadas.empty() ? "" : camadas.begin()->first;
        }
    }
}

void Canvas::listar_camadas() const {
    std::cout << "Camadas do canvas:\n";
    for (const auto& par : camadas) {
        std::cout << "- " << par.first;
        if (par.first == camada_ativa) std::cout << " [ativa]";
        std::cout << " | formas: " << par.second.tamanho() << '\n';
    }
}

void Canvas::definir_camada_ativa(const std::string& nome) {
    if (camadas.find(nome) == camadas.end()) {
        throw std::runtime_error("Camada nao encontrada.");
    }
    camada_ativa = nome;
}

std::string Canvas::get_camada_ativa() const { return camada_ativa; }

void Canvas::adicionar_forma(Forma* forma, const std::string& nome_camada) {
    const std::string destino = nome_camada.empty() ? camada_ativa : nome_camada;
    if (camadas.find(destino) == camadas.end()) {
        criar_camada(destino);
    }
    camadas[destino].adicionar(forma);
}

void Canvas::remover_forma(const std::string& nome_camada, int indice, bool destruir) {
    auto it = camadas.find(nome_camada);
    if (it != camadas.end() && indice >= 0 && indice < it->second.tamanho()) {
        Forma* alvo = it->second.get_elementos_mutavel()[indice];
        it->second.remover(indice);
        if (destruir) delete alvo;
    }
}

void Canvas::listar_formas_camada(const std::string& nome_camada) const {
    auto it = camadas.find(nome_camada);
    if (it == camadas.end()) {
        std::cout << "Camada nao encontrada.\n";
        return;
    }
    it->second.listar();
}

std::vector<Forma*> Canvas::get_todas_formas() const {
    std::vector<Forma*> todas;
    for (const auto& par : camadas) {
        for (Forma* forma : par.second.get_elementos()) {
            todas.push_back(forma);
        }
    }
    return todas;
}

Camada<Forma>* Canvas::obter_camada(const std::string& nome) {
    auto it = camadas.find(nome);
    if (it == camadas.end()) return nullptr;
    return &it->second;
}

const std::map<std::string, Camada<Forma>>& Canvas::get_camadas() const {
    return camadas;
}

void Canvas::exportar_svg(const std::string& arquivo) const {
    std::ofstream out(arquivo);
    if (!out) {
        throw std::runtime_error("Nao foi possivel criar o arquivo SVG.");
    }

    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    out << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << largura
        << "\" height=\"" << altura << "\" viewBox=\"0 0 "
        << largura << ' ' << altura << "\">\n";
    out << "<rect width=\"100%\" height=\"100%\" fill=\"" << cor_fundo.to_hex() << "\"/>\n";

    for (const auto& par : camadas) {
        out << "<g id=\"camada_" << par.first << "\">\n";
        for (const Forma* forma : par.second.get_elementos()) {
            out << forma->to_svg() << '\n';
        }
        out << "</g>\n";
    }

    out << "</svg>\n";
}

int Canvas::get_largura() const { return largura; }
int Canvas::get_altura() const { return altura; }
Cor Canvas::get_cor_fundo() const { return cor_fundo; }
void Canvas::set_tamanho(int nova_largura, int nova_altura) { largura = nova_largura; altura = nova_altura; }
void Canvas::set_cor_fundo(const Cor& cor) { cor_fundo = cor; }
