#ifndef PEDIDO_H
#define PEDIDO_H

#include "Cliente.h"
#include "Prato.h"

class Pedido{
    Cliente cliente;
    Prato prato;
    string endereco;
public:
    Pedido(Cliente cliente, Prato prato, string endereco);
    friend ostream& operator<<(ostream& os, const Pedido& pedido);
};

#endif