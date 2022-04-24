#ifndef PRATO_H
#define PRATO_H

#include <iostream>
#include <string>

using namespace std;

class Prato{
    string nome, descricao;
    float preco;
public:
    Prato();
    Prato(string nome, string descricao, float preco);
    string getNome();
    void setNome(string nome);
    string getDescricao();
    void setDescricao(string descricao);
    float getPreco();
    void setPreco(float preco);
    friend ostream& operator<<(ostream& os, const Prato& prato);
};

#endif