#include "Restaurante.h"

Restaurante::Restaurante(string nome, string endereco, string senha){
    this->nome = nome;
    this->endereco = endereco;
    this->senha = senha;
}

string Restaurante::getNome(){
    return this->nome;
}

void Restaurante::setNome(string nome){
    this->nome = nome;
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