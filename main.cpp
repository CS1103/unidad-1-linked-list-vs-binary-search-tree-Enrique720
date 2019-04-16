#include <iostream>
#include <sstream>
#include <string>

#include <vector>
#include <fstream>
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList* ll = new LinkedList;
    BinarySearchTree* bst = new BinarySearchTree;
    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll
    // Grabar Datos del archivo "Locations.csv" en bst
    load_locations(bst,"Locations.csv");
    load_locations(ll,"Locations.csv");
    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    std::fstream file("Searcht.txt",std::ios::in);
    int a = 0;
    while ( file >> a){
        vsearch.push_back(a);
    }
    double avgtime_ll = 0;
    double avgtime_bst = 0;

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    for (const auto& id: vsearch) {
        // Buscar en ll
        ll->search(id);
        // Buscar en bsd
        bst->search(id);
    }


    return 0;
}
