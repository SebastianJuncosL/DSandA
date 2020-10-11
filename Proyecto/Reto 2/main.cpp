#include "Conexiones.h"

int main()
{
    ConexionesComputadora john("john.reto.com", "34");
    john.obtenerConexionesE();
    john.printConexionesE();
    std::cout << "\n" << std::endl;
    john.obtenerConexionesS();
    john.printConexionesS();
    john.repeatedConnections();

    return 0;
}
