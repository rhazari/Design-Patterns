#include "vehicleFactory.h"

using namespace std;

int main(){
    Vehicle *v;
    // Car
    v = VehicleFactory::createVehicle(VehicleType::Car);
    v->display();
    delete v;

    // Truck
    v = VehicleFactory::createVehicle(VehicleType::Truck);
    v->display();
    delete v;

    return 0;
}