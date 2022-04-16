#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *tiposProductos[] = { "Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas" };

struct Producto {
    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;
} typedef Producto;

struct Cliente {
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *productos;
} typedef Cliente;

void cargarCliente(Cliente* cliente, int idCliente);
void cargarClientes(Cliente* listadoClientes, int cantidadClientes);
void cargarProductos(Producto* listadoProductos, int cantidadProductos);
void mostrarCliente(Cliente* cliente);
void mostrarClientes(Cliente* listadoClientes, int cantidadClientes);
float totalProducto(Producto producto);

int main() {
    
    srand((int)time(NULL));

    int cantidadClientes;
    char *Buff;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);
    fflush(stdin);

    Cliente *listadoClientes = (Cliente *) malloc( cantidadClientes * sizeof(Cliente) );

    cargarClientes(listadoClientes, cantidadClientes);
    mostrarClientes(listadoClientes, cantidadClientes);

    return 0;
};

void cargarCliente(Cliente* cliente, int idCliente) {
    
    cliente->clienteID = idCliente;

    char *Buff = (char *) malloc(sizeof(char) * 50);
    printf("Nombre del cliente: ");
    gets(Buff);

    cliente->nombreCliente = (char *) malloc(sizeof(char) * (strlen(Buff) + 1));
    strcpy(cliente->nombreCliente, Buff);

    cliente->cantidadProductosAPedir = 1 + rand() % 5;

    cliente->productos = (Producto *) malloc(sizeof(Producto) * cliente->cantidadProductosAPedir);

    cargarProductos(cliente->productos, cliente->cantidadProductosAPedir);

    free(Buff);
};

void cargarClientes(Cliente* listadoClientes, int cantidadClientes) {

    for (int i = 0; i < cantidadClientes; i++) {
        cargarCliente(listadoClientes, i + 1);

        listadoClientes++;
    };
};

void cargarProductos(Producto* listadoProductos, int cantidadProductos) {
    for (int i = 0; i < cantidadProductos; i++) {
        listadoProductos[i].productoID = i + 1;
        listadoProductos[i].cantidad = 1 + rand() % 10;
        listadoProductos[i].precioUnitario = 1 + rand() % 100;

        listadoProductos[i].tipoProducto = (char *) malloc(sizeof(char) * strlen(tiposProductos[rand() % 5] + 1));
        strcpy(listadoProductos[i].tipoProducto, tiposProductos[rand() % 5]);
    };
};

void mostrarCliente(Cliente* cliente) {
    float totalCompra;

    printf("\n------------------------------\n");
    printf("ID cliente: %d\n", cliente->clienteID);
    printf("Nombre del cliente: %s\n", cliente->nombreCliente);
    printf("Cantidad de productos pedidos: %d\n", cliente->cantidadProductosAPedir);

    printf("\n----- Resumen compra -----\n");

    for (int i = 0; i < (cliente->cantidadProductosAPedir); i++) {

        printf("\nId producto: %d\n", cliente->productos[i].productoID);
        printf("Tipo producto: %s\n", cliente->productos[i].tipoProducto);
        printf("Precio unitario: %.2f\n", cliente->productos[i].precioUnitario);
        printf("Cantidad: %d\n", cliente->productos[i].cantidad);
        printf("Total producto: $%.2f\n", totalProducto(cliente->productos[i]));

        totalCompra += totalProducto(cliente->productos[i]);
    };

    printf("\nTotal compra: $%.2f", totalCompra);
    printf("\n------------------------------\n");
};

void mostrarClientes(Cliente* listadoClientes, int cantidadClientes) {
    
    for (int i = 0; i < cantidadClientes; i++) {

        mostrarCliente(listadoClientes);
        free(listadoClientes);
        
        listadoClientes++;
    };
};

float totalProducto(Producto producto) {
    return producto.cantidad * producto.precioUnitario;
};
