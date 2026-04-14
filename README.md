# 🖼️ PolyArt — Editor de Arte Vetorial

Projeto desenvolvido para a disciplina de **Programação Orientada a Objetos (POO)**, com implementação em **C++**, focado na criação e manipulação de formas geométricas e exportação para **SVG**.

---

## 📌 Descrição

O **PolyArt** é um editor de arte vetorial via terminal que permite:

- Criar formas geométricas (círculo, retângulo, triângulo, linha, polígono)
- Organizar formas em camadas
- Agrupar formas (composição)
- Aplicar operações como movimentação e alteração de cores
- Exportar o resultado para um arquivo **SVG válido**, visualizável em navegadores

---

## 📂 Estrutura do Projeto

```
polyart/
├── include/
├── src/
├── exemplos/
├── docs/
├── Makefile
└── README.md
```

---

## ⚙️ Funcionalidades

- Classe base abstrata `Forma`
- Herança e polimorfismo
- Classe `Grupo` (composição)
- Template `Camada<T>`
- `Canvas` Singleton
- Exportação para SVG

---

## 🖥️ Compilação e Execução

### Linux / MSYS2

```
make
./polyart
```

### Windows

```
g++ -std=c++17 -Wall -Wextra src/*.cpp -Iinclude -o polyart.exe
./polyart.exe
```

---

## 🖼️ Exemplos

Arquivos gerados na pasta:

```
exemplos/
```

---

## 👨‍💻 Autor

José Victor Justino de Oliveira
