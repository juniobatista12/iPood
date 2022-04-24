#include "Restaurante.h"

Restaurante::Restaurante(string nome, string cnpj, string endereco, string senha){
    this->nome = nome;
    this->cnpj = cnpj;
    this->endereco = endereco;
    this->senha = senha;
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