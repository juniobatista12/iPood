#include "Cliente.h"
#include "Restaurante.h"

#include <fstream>

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
    cout << "Usuario cadastrado com sucesso" << endl;
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
    cout << "Restaurante cadastrado com sucesso" << endl;
}

bool loginCliente(vector<Cliente> clientes, Cliente& tmp){
    string cpf, senha;
    cout << "CPF: ";
    getline(cin, cpf);
    cout << "Senha: ";
    getline(cin, senha);
    for(auto cliente : clientes){
        if (cliente.getCPF() == cpf){
            tmp = cliente;
            return cliente.testSenha(senha);
        }
    }
    return false;
}

void buscaRestaurante(vector<Restaurante> restaurantes){
    string setor;
    int i = 0;
    cout << "Digite o setor que deseja buscar: ";
    getline(cin, setor);
    for (auto restaurante: restaurantes){
        if(restaurante.getSetor() == setor){
            cout << "ID: " << i << " ";
            cout << restaurante << endl;
        }
        i++;
    }
}

void efetuaCompra(vector<Restaurante>& restaurantes, Cliente cliente){
    int id1, id2, id3;
    float avaliacao;
    cout << "Digite o ID do restaurante desejado: ";
    cin >> id1;
    while(getchar() != '\n');
    if (id1 < restaurantes.size()){
        restaurantes[id1].printCardapio();
        cout << "Digite o ID do prato que deseja comprar: ";
        cin >> id2;
        while(getchar() != '\n');
        cliente.printEnderecos();
        cout << endl << endl;
        cout << "Digite o ID do endereco que deseja a entrega: ";
        cin >> id3;
        while(getchar() != '\n');
        restaurantes[id1].addPedido(cliente, id2,cliente.getEnderecoById(id3));
        cout << "Agora avalie o restaurante com uma nota entre 0 e 5: ";
        cin >> avaliacao;
        while(getchar() != '\n');
        restaurantes[id1].adicionaAvaliacao(avaliacao);
    }
    else{
        cout << "ID invalido\n";
    }
}

void clienteLogado(vector<Restaurante>& restaurantes, Cliente& cliente){
    int opt;
    string tmp;
    cout << "Cliente " << cliente.getNome() << " logado" << endl;

    do{
        cout << "1 - Buscar restaurante por setor\n2 - Realizar compra em restaurante por ID\n3 - Trocar senha\n4 - Adicionar Endereco\n0 - Sair\nOpcao: ";
        cin >> opt;
        while(getchar() != '\n');
        switch(opt){
        case 1:
            buscaRestaurante(restaurantes);
            break;
        case 2:
            efetuaCompra(restaurantes, cliente);
            break;
        case 3:
            cout << "Digite a nova senha: ";
            getline(cin, tmp);
            cliente.setSenha(tmp);
            break;
        case 4:
            cout << "Digite o endereco a ser inserido: ";
            getline(cin, tmp);
            cliente.addEndereco(tmp);
            break;
        }
    }while(opt != 0);
}

bool loginRestaurante(vector<Restaurante> restaurantes, int& tmp){
    string CNPJ, senha;
    cout << "CNPJ: ";
    getline(cin, CNPJ);
    cout << "Senha: ";
    getline(cin, senha);
    int i = 0;
    for(auto restaurante : restaurantes){
        if (restaurante.getCNPJ() == CNPJ){
            tmp = i;
            return restaurante.testSenha(senha);
        }
        i++;
    }
    return false;
}

void restauranteLogado(vector<Restaurante>& restaurantes, int id){
    cout << "Restaurante " << restaurantes[id].getNome() << " logado\n";
    int opt;
    string nt, dt;
    float pt;
    do{
        cout << "1 - Adicionar prato\n2 - Verificar cardapio\n3 - Verificar pedidos\n0 - Sair\nOpcao: ";
        cin >> opt;
        while(getchar() != '\n');
        switch(opt){
        case 1:
            cout << "Digite o nome do prato: ";
            getline(cin, nt);
            cout << "Digite uma descricao para o prato: ";
            getline(cin, dt);
            cout << "Digite o preco do prato: ";
            cin >> pt;
            while(getchar() != '\n');
            restaurantes[id].addPrato(nt, dt, pt);
            break;
        case 2:
            restaurantes[id].printCardapio();
            break;
        case 3:
            restaurantes[id].printPedidos();
            break;
        }
    }while(opt != 0);
}

template <typename T>void verificaVetor(vector<T> vetor){
    unsigned int i = 0;
    for (auto item : vetor){
        cout << "ID: " << i++ << " ";
        cout << item << endl;
    }
}

int main(){
    int opt;
    vector<Cliente> clientes;
    vector<Restaurante> restaurantes;
    do{
        Cliente tmpc;
        int tmpr;
        cout << "1 - Cadastrar novo Cliente\n2 - Cadastrar novo Restaurante\n3 - Logar como Cliente\n4 - Logar como Restaurante\n5 - Verificar Clientes\n6 - Verificar Restaurantes\n0 - Sair\nOpcao: ";
        cin >> opt;
        while(getchar() != '\n');
        switch(opt){
        case 1:
            cadastraCliente(clientes);
            break;
        case 2:
            cadastraRestaurante(restaurantes);
            break;
        case 3:
            if(loginCliente(clientes, tmpc)){
                clienteLogado(restaurantes, tmpc);
            }
            else{
                cout << "Erro ao logar\n";
            }
            break;
        case 4:
            if(loginRestaurante(restaurantes, tmpr)){
                restauranteLogado(restaurantes, tmpr);
            }
            else{
                cout << "Erro ao logar\n";
            }
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
