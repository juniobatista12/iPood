#include "Restaurante.h"

Restaurante::Restaurante(){}

Restaurante::Restaurante(string nome, string cnpj, string endereco, string setor, string senha){
    this->nome = nome;
    this->cnpj = cnpj;
    this->endereco = endereco;
    this->setor = setor;
    this->senha = senha;
    this->reputacao = 0;
}

string Restaurante::getNome(){
    return this->nome;
}

void Restaurante::setNome(string nome){
    this->nome = nome;
}

string Restaurante::getCNPJ(){
    return this->cnpj;
}

void Restaurante::setCNPJ(string cnpj){
    this->cnpj = cnpj;
}

string Restaurante::getEndereco(){
    return this->endereco;
}

void Restaurante::setEndereco(string endereco){
    this->endereco = endereco;
}

string Restaurante::getSetor(){
    return this->setor;
}

bool Restaurante::testSenha(string senha){
    return this->senha == senha;
}

void Restaurante::setSenha(string senha){
    this->senha = senha;
}

void Restaurante::atualizaReputacao(){
    float soma = 0;
    for(float avaliacao : this->avaliacoes){
        soma += avaliacao;
    }
    this->reputacao = soma / this->avaliacoes.size();
}

void Restaurante::adicionaAvaliacao(float avaliacao){
    avaliacoes.push_back(avaliacao);
    this->atualizaReputacao();
}

void Restaurante::printCardapio(){
    int i = 0;
    for (auto prato : this->cardapio){
        cout << "ID: " << i++ << " " << prato << endl;
    }
}

void Restaurante::addPedido(Cliente cliente, unsigned int id, string endereco){
    this->pedidos.push_back(Pedido(cliente, this->cardapio[id], endereco));
}

ostream& operator<<(ostream& os, const Restaurante& restaurante){
    os << "Restaurante: " << restaurante.nome << "\tEndereco: " << restaurante.endereco << "\tSetor:" << restaurante.setor << "\t CNPJ: " << restaurante.cnpj << "\tReputacao: " << restaurante.reputacao << endl;
    return os;
}