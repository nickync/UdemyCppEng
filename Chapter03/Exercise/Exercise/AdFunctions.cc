#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace
{

void init_vehicle(Ad::Types::VehicleType &vehicle,
        const std::int32_t id,
        const float speed_kph,
        const float distance_m,
        const Ad::Types::LaneAssociationType lane)
        {
            vehicle.id = id;
            vehicle.speed_mps = Ad::Utils::kph_to_mps(speed_kph);
            vehicle.distance_m = distance_m;
            vehicle.lane  = lane;
        }
}

namespace Ad
{
namespace Utils
{
    float kph_to_mps(const float kph)
    {
        return kph/3.6F;
    }
}

namespace Data
{
    Ad::Types::VehicleType init_ego_vehicle()
    {
        return Ad::Types::VehicleType{
            .id = Ad::Constants::EGO_VEHICLE_ID,
            .lane = Ad::Types::LaneAssociationType::CENTER,
            .speed_mps = Ad::Utils::kph_to_mps(135.0F),
            .distance_m = 0.0F,
        };
    }

    Ad::Types::NeighborVehiclesType init_vehicles()
    {
        auto vehicles = Ad::Types::NeighborVehiclesType{};

        init_vehicle(vehicles.Left[0],
                    0,
                    130.0F,
                    80.0F,
                    Ad::Types::LaneAssociationType::LEFT);

        init_vehicle(vehicles.Left[1],
            1,
            80.0F,
            -20.0F,
            Ad::Types::LaneAssociationType::LEFT);


        init_vehicle(vehicles.Center[0],
            2,
            120.0F,
            80.0F,
            Ad::Types::LaneAssociationType::LEFT);


        init_vehicle(vehicles.Center[1],
            3,
            130.0F,
            80.0F,
            Ad::Types::LaneAssociationType::LEFT);
    }
}

namespace Visualize
{

void print_vehicle(const Ad::Types::VehicleType &vehicle)
{
    std::cout << "ID : " << vehicle.id << '\n';
    std::cout << " Speed : " << vehicle.speed_mps;
}

void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles)
{
    print_vehicle( vehicles.Left[0]);
    print_vehicle( vehicles.Left[1]);
    print_vehicle( vehicles.Center[0]);
    print_vehicle( vehicles.Center[1]);
}

void print_scene(const Ad::Types::VehicleType &ego_vehicle,
                 const Ad::Types::NeighborVehiclesType &vehicles)
{

}

} // namespace Visualize
} // namespace Add
