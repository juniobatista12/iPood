#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Prato.h"
#include <vector>

class Restaurante{
    string nome, cnpj, endereco, senha;
    vector<Prato> cardapio;
    float reputacao;
    vector<float> avaliacoes;
    void atualizaReputacao();
public:
    Restaurante(string nome, string cnpj, string endereco, string senha);
    string getNome();
    void setNome(string nome);
    string getCNPJ();
    void setCNPJ(string cnpj);
    string getEndereco();
    void setEndereco(string endereco);
    bool testSenha(string senha);
    void setSenha(string senha);
    void adicionaAvaliacao(float avaliacao);
    friend ostream& operator<<(ostream& os, const Restaurante& restaurante);
};

#endif