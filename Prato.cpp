#include "Prato.h"

Prato::Prato(string nome, string descricao, float preco){
    this->nome = nome;
    this->descricao = descricao;
    this->preco = preco;
}

string Prato::getNome(){
    return this->nome;
}

void Prato::setNome(string nome){
    this->nome = nome;
}

string Prato::getDescricao(){
    return this->descricao;
}

void Prato::setDescricao(string descricao){
    this->descricao = descricao;
}

float Prato::getPreco(){
    return this->preco;
}

void Prato::setPreco(float preco){
    this->preco = preco;
}

ostream& operator<<(ostream& os, const Prato& prato){
    os << "Prato: " << prato.nome << "\nDescricao: " << prato.descricao << "\n\nPreco: " << prato.preco << "\n\n";
}