#include "Datos.h"

int main()
{
    // Creamos la clase con el vector de la clase que
    // contiene los datos del csv
    Datos datos;
    // Cuántos registros tiene el archivo? ---------------------------
    // cout << datos.getNoDeDatos() << endl;

    // Datos en el segundo día ---------------------------------------
    // Primero ordenamos por dia
    //datos.ordenarPorFecha();
    // listamos los días para poder obtener el 2ndo dia
    //datos.listarFechas();
    // Buscamos la fecha y con eso obtenemos el numero
    // total de registros que hay para ese dia
    //datos.buscarPorFecha("11-8-2020");

    // Computadoras pertenecientes a Jeffrey,
    // Betty, Katherine, Scott, Benjamin, Samuel o Raymond -----------
    // Ordenamos por Hostname Fuente
    // datos.ordenarPorHostnameFuente();
    // Mostramos todos los hostname fuente (opcional)
    //datos.listarHostnameFuente();
    // Buscamos los nombres
    // datos.buscarPorHostnameFuente("jeffrey");
    // datos.buscarPorHostnameFuente("betty");
    // datos.buscarPorHostnameFuente("katherine");
    // datos.buscarPorHostnameFuente("scott");
    // datos.buscarPorHostnameFuente("benjamin");
    // datos.buscarPorHostnameFuente("samuel");
    // datos.buscarPorHostnameFuente("raymond");
    // Mostramos todos los hostname fuente (opcional)
    //datos.listarHostnameFuente();

    // Buscamos por  hostname fuente de server.reto ------------------
    // Ordenamos por hostname fuente
    // datos.ordenarPorHostnameFuente();
    // Buscamos server.reto en los hostnames Fuente
    // datos.buscarPorHostnameFuente("server.reto");
    // Buscamos server.reto en los hostnames Destino
    // datos.buscarPorHostnameDestino("server.reto");
    // Mostramos todos los hostname fuente y destino(opcional)
    // datos.listarHostnameFuente();

    // Servicio de mail-----------------------------------------------
    // Ordenmaos por hostname destino
    // datos.ordenarPorHostnameDestino();
    // Mostramos los hostname destino
    // datos.listarHostnameDestino();
    // Sabiendo que utilizan mail.yahoo.com y protonmail.com
    // poemos obtener el numero de veces que se accedio a cada uno
    // datos.buscarPorHostnameDestino("mail.yahoo");
    // datos.buscarPorHostnameDestino("protonmail");

    // Buscar puertos destino menores a 100---------------------------
    // Ordenamos por puertos destino
    datos.ordenarPorPuertoDestino();
    // Listamos los puertos
    datos.listarPuertosDestino();
    return 0;
}