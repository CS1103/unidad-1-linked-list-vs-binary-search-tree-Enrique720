#include "Location.h"
Location::Location(int position_id, std::string state_code, std::string county, double latitude, double longitude,
                   std::string line, std::string construction): position_id{ position_id} , state_code{ state_code},county{county} ,
                   latitude{latitude},longitude{longitude}{}
void Location::imprimir_Location() {
    std::cout << position_id << " " << state_code << " " << county << " " << latitude << " " << longitude << " " << line << " " << construction << std::endl;
}
int Location::get_pos() {
    return position_id;
}
// Defina los metodos que crea necesario
