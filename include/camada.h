#ifndef CAMADA_H
#define CAMADA_H

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class Camada {
private:
    std::string nome;
    std::vector<T*> elementos;

public:
    Camada(const std::string& nome = "sem_nome") : nome(nome) {}

    void adicionar(T* elem) {
        if (elem != nullptr) {
            elementos.push_back(elem);
        }
    }

    void remover(int indice) {
        if (indice >= 0 && indice < static_cast<int>(elementos.size())) {
            elementos.erase(elementos.begin() + indice);
        }
    }

    void listar() const {
        std::cout << "Camada: " << nome << "\n";
        for (size_t i = 0; i < elementos.size(); ++i) {
            std::cout << "[" << i << "] ";
            elementos[i]->info();
        }
    }

    void ordenar_por_area() {
        std::sort(elementos.begin(), elementos.end(), [](T* a, T* b) {
            return a->area() < b->area();
        });
    }

    int tamanho() const {
        return static_cast<int>(elementos.size());
    }

    const std::vector<T*>& get_elementos() const {
        return elementos;
    }

    std::vector<T*>& get_elementos_mutavel() {
        return elementos;
    }

    std::string get_nome() const {
        return nome;
    }
};

#endif
