#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente{
    string nome, cpf, email, senha;
    vector<string> enderecos;
    
public:
    Cliente();
    Cliente(string nome, string cpf, string email, string senha);
    string getNome();
    void setNome(string nome);
    string getCPF();
    void setCPF(string cpf);
    string getEmail();
    void setEmail(string email);
    bool testSenha(string senha);
    void setSenha(string senha);
    vector<string> getEndereco();
    void printEnderecos();
    void addEndereco(string endereco);
    void removeEndereco(int id);
    string getEnderecoById(int id);
    friend ostream& operator<<(ostream& os, const Cliente& cliente);
};

#endif
