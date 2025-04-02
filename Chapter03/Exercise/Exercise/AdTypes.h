#pragma once

#include <cstdint>

#include "AdConstants.h"

namespace Ad
{
namespace Types
{

enum class LaneAssociationType
{
    LEFT,
    CENTER,
    RIGHT,
    NONE,
};

struct VehicleType
{
    std::int32_t id;
    LaneAssociationType lane;
    float speed_mps;
    float distance_m;
};

struct NeighborVehiclesType
{
    std::array<VehicleType, 2> Left = {};
    std::array<VehicleType, 2> Right = {};
    std::array<VehicleType, 2> Center = {};
};

} // namespace Types
} // namespace Ad
