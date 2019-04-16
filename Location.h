//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LOCATION_H
#define LINKEDLISTVSBINARYTREE_LOCATION_H
#include <string>
#include <iostream>
class Location {
    int position_id;
    std::string state_code;
    std::string county;
    double latitude;
    double longitude;
    std::string line;
    std::string construction;
public:
    int get_pos();
    Location(
            int position_id,
            std::string state_code,
            std::string county,
            double latitude,
            double longitude,
            std::string line,
            std::string construction);
    void imprimir_Location();
    // Declare los metodos que crea necesario

    // Cree que sea necesario agregar destructor, justifique

};


#endif //LINKEDLISTVSBINARYTREE_LOCATION_H
