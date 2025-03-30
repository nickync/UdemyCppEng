#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace Ad
{

namespace Utils
{
    float kph_to_mps(const float kph){
        return kph / 3.6F;
    }
}

namespace Data
{

Ad::Types::VehicleType init_ego_vehicle()
{
    return Ad::Types::VehicleType{
        .id = Ad::Constants::EGO_VEHICLE_ID,
        .lane = Ad::Types::LaneAssociationType::CENTER,
        .speed = Ad::Utils::kph_to_mps(135.0F),
        .distance = 99.0F,
    };
}

}

namespace Visualize
{
void print_vehicle(const Ad::Types::VehicleType vehicle)
{
    std::cout << " ID : " << vehicle.id << '\n';
    std::cout << " Speed " << vehicle.speed << '\n';
    std::cout << " Distance : " << vehicle.distance << '\n';
    std::cout << " Lane: " << static_cast<std::int32_t>(vehicle.lane) << '\n';
}
}

}
