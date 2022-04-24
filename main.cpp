#include "Cliente.h"
#include "Restaurante.h"

void cadastraCliente(vector<Cliente>& clientes){
    string nome, cpf, email, senha;
    cout << "Digite seu nome: ";
    getline(cin, nome);
    // while(getchar() != '\n');
    cout << "Digite seu CPF: ";
    getline(cin, cpf);
    // while(getchar() != '\n');
    cout << "Digite seu email: ";
    getline(cin, email);
    // while(getchar() != '\n');
    cout << "Digite sua senha: ";
    getline(cin, senha);
    // while(getchar() != '\n');
    clientes.push_back(Cliente(nome, cpf, email, senha));
    cout << "Usuário cadastrado com sucesso" << endl;
}

void cadastraRestaurante(vector<Restaurante>& restaurantes){
    string nome, endereco, cnpj, senha;
    cout << "Digite seu nome: ";
    getline(cin, nome);
    // while(getchar() != '\n');
    cout << "Digite seu CNPJ: ";
    getline(cin, cnpj);
    // while(getchar() != '\n');
    cout << "Digite seu endereco: ";
    getline(cin, endereco);
    // while(getchar() != '\n');
    cout << "Digite sua senha: ";
    getline(cin, senha);
    // while(getchar() != '\n');
    restaurantes.push_back(Restaurante(nome, cnpj, endereco, senha));
    cout << "Usuário cadastrado com sucesso" << endl;
}

void verificaClientes(vector<Cliente> clientes){
    for (Cliente cliente : clientes){
        cout << cliente << endl;
    }
}

int main(){
    int opt;
    vector<Cliente> clientes;
    vector<Restaurante> restaurantes;
    do{
        cout << "1 - Cadastrar novo Cliente\n2 - Cadastrar novo Restaurante\n3 - Logar como Cliente\n4 - Logar como Restaurante\n5 - Verificar Clientes\n0 - Sair\n";
        cin >> opt;
        while(getchar() != '\n');
        switch(opt){
        case 1:
            cadastraCliente(clientes);
            break;
        case 2:
            cadastraRestaurante(restaurantes);
            break;
        case 5:
            verificaClientes(clientes);
            break;
        }
    }while(opt != 0);
}