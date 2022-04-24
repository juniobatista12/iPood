#include "Pedido.h"

Pedido::Pedido(Cliente cliente, Prato prato, string endereco){
    this->cliente = cliente;
    this->prato = prato;
    this->endereco = endereco;
}
ostream& operator<<(ostream& os, const Pedido& pedido){
    os << "Cliente: " << pedido.cliente << "\nPrato: " << pedido.prato;
    return os;
}