#include "vehicle.h"

using namespace std;

enum class VehicleType {
    Car,
    Truck
};

class VehicleFactory {
public:
    static Vehicle* createVehicle(VehicleType type){
        Vehicle *ptr;
        switch(type){
            case VehicleType::Car:{
                ptr = new Car;
                break;
            }
            case VehicleType::Truck:{
                ptr = new Truck;
                break;
            }
            default: {
                cout<<"Invalid vehicle type"<<"\n";
                ptr = nullptr;
            }
        }

        ptr->assemble();
        ptr->applyChecks();
        ptr->applyLabel();
        ptr->deliver();

        return ptr;
    }
};