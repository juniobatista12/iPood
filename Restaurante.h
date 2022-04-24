#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Prato.h"
#include <vector>

class Restaurante{
    string nome, endereco, senha;
    vector<Prato> cardapio;
    float reputacao;
    vector<float> avaliacoes;
public:
    Restaurante(string nome, string endereco, string senha);
    string getNome();
    void setNome(string nome);
    string getEndereco();
    void setEndereco(string endereco);
    bool testSenha(string senha);
    void setSenha(string senha);
};

#endif