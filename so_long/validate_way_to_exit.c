#include "so_long.h"

// necesitamos saber el ancho y alto del mapa
// identificar la posicion de inicio('P') y salida('E')
// usaremos el algoritmo de busqueda BFS (Breadth First Search) para encontrar la salida
// BFS es un algoritmo de busqueda de grafos que comienza en el nodo raiz y explora todos los vecinos a la vez
// pensar como representar los nodos del mapa y las conexiones: nodos son las posiciones en el mapa
// y conexiones son las posiciones adyacentes que se pueden alcanzar desde la posicion actual
// necesitamos una estructura de datos para almacenar los nodos y conexiones

int validate_way_to_exit(char *map, int x, int y, int width, int height)
{
    // Verificar si las coordenadas estan dentro del mapa
    if (x < 0 || x >= width || y < 0 || y >= height)
        return (0);

    // Verificar si la posicion actual no es una pared
    if (map[y * width + x] == '1')
        return (0);

    // La posicion es valida si pasa las dos condiciones anteriores
    return (1);
}