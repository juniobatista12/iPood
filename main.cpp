#include "Cliente.h"
#include "Restaurante.h"

void cadastraCliente(vector<Cliente>& clientes){
    string nome, cpf, email, senha;
    cout << "Digite seu nome: ";
    getline(cin, nome);
    cout << "Digite seu CPF: ";
    getline(cin, cpf);
    cout << "Digite seu email: ";
    getline(cin, email);
    cout << "Digite sua senha: ";
    getline(cin, senha);
    clientes.push_back(Cliente(nome, cpf, email, senha));
    cout << "Usuário cadastrado com sucesso" << endl;
}

void cadastraRestaurante(vector<Restaurante>& restaurantes){
    string nome, endereco, setor, cnpj, senha;
    cout << "Digite seu nome: ";
    getline(cin, nome);
    cout << "Digite seu CNPJ: ";
    getline(cin, cnpj);
    cout << "Digite seu endereco: ";
    getline(cin, endereco);
    cout << "Digite seu setor: ";
    getline(cin, setor);
    cout << "Digite sua senha: ";
    getline(cin, senha);
    restaurantes.push_back(Restaurante(nome, cnpj, endereco, setor, senha));
    cout << "Usuário cadastrado com sucesso" << endl;
}

template <typename T> void verificaVetor(vector<T> vetor){
    for (auto item : vetor){
        cout << item << endl;
    }
}

int main(){
    int opt;
    vector<Cliente> clientes;
    vector<Restaurante> restaurantes;
    do{
        cout << "1 - Cadastrar novo Cliente\n2 - Cadastrar novo Restaurante\n3 - Logar como Cliente\n4 - Logar como Restaurante\n5 - Verificar Clientes\n6 - Verificar Restaurantes\n0 - Sair\n";
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
            verificaVetor(clientes);
            break;
        case 6:
            verificaVetor(restaurantes);
            break;
        }
    }while(opt != 0);
}