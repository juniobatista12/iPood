#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Pedido.h"
#include "Prato.h"
#include <vector>

class Restaurante{
    string nome, cnpj, endereco, setor, senha;
    vector<Prato> cardapio;
    float reputacao;
    vector<float> avaliacoes;
    vector<Pedido> pedidos;
    void atualizaReputacao();
public:
    Restaurante();
    Restaurante(string nome, string cnpj, string endereco, string setor, string senha);
    string getNome();
    void setNome(string nome);
    string getCNPJ();
    void setCNPJ(string cnpj);
    string getEndereco();
    void setEndereco(string endereco);
    string getSetor();
    bool testSenha(string senha);
    void setSenha(string senha);
    void adicionaAvaliacao(float avaliacao);
    void printCardapio();
    void addPedido(Cliente cliente, unsigned int id, string endereco);
    friend ostream& operator<<(ostream& os, const Restaurante& restaurante);
};

#endif