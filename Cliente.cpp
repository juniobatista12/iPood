#include "Cliente.h"

Cliente::Cliente(){
    
}

Cliente::Cliente(string nome, string cpf, string email, string senha){
    this->nome = nome;
    this->cpf = cpf;
    this->email = email;
    this->senha = senha;
}

string Cliente::getNome(){
    return this->nome;
}

void Cliente::setNome(string nome){
    this->nome = nome;
}

string Cliente::getCPF(){
    return this->cpf;
}

void Cliente::setCPF(string cpf){
    this->cpf = cpf;
}

string Cliente::getEmail(){
    return this->email;
}

void Cliente::setEmail(string email){
    this->email = email;
}

bool Cliente::testSenha(string senha){
    return this->senha == senha;
}

void Cliente::setSenha(string senha){
    this->senha = senha;
}

vector<string> Cliente::getEndereco(){
    return this->enderecos;
}

void Cliente::printEnderecos(){
    int i = 0;
    for(auto endereco : this->enderecos){
        cout << "ID: " << i++ << "\tEndereco: " << endereco;
    }
}

void Cliente::addEndereco(string endereco){
    this->enderecos.push_back(endereco);
}
void Cliente::removeEndereco(int id){
    this->enderecos.erase(this->enderecos.begin() + id);
}

string Cliente::getEnderecoById(int id){
    return this->enderecos[id];
}

ostream& operator<<(ostream& os, const Cliente& cliente){
    os << "Nome: " << cliente.nome << "\tCPF: " << cliente.cpf << "\tEmail: " << cliente.email;
    return os;
}