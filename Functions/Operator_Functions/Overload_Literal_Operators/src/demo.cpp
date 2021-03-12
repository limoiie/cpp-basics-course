#include "demo.h"

#include <chrono>

namespace distance
{

    template<long Centimeters>
    struct distance_unit {
        static const long centimeters = Centimeters;
    };

    template<typename T>
    struct distance {
        unsigned count;

        std::string to_string() const {
            return std::to_string(count).append(" * ")
                    .append(std::to_string(T::centimeters))
                    .append(" centimeters");
        }
    };

    using centimeters = distance<distance_unit<1>>; // 1 cm == 1 cm
    using meters = distance<distance_unit<1000>>; // 1 m == 1000 cm
    using kilometers = distance<distance_unit<1000 * 1000>>; // 1 km == 1000 * 1000 cm

    inline namespace literals
    {

        constexpr centimeters operator "" _cm(unsigned long long cm_count) {
            return centimeters{static_cast<unsigned>(cm_count)};
        }

        constexpr meters operator "" _m(unsigned long long cm_count) {
            return meters {static_cast<unsigned>(cm_count)};
        }

        constexpr kilometers operator "" _km(unsigned long long cm_count) {
            return kilometers {static_cast<unsigned>(cm_count)};
        }

        constexpr centimeters operator "" _cm(long double cm_count) {
            return centimeters{static_cast<unsigned>(cm_count)};
        }

    }

}

DEMO(OverloadLiteralOperators, LiteralOperators) { // NOLINT(cert-err58-cpp)

    using namespace distance;

    auto const l_cm = 100_cm;
    std::cout << "100_cm: " << l_cm.to_string() << std::endl;

    auto const l_m = 90_m;
    std::cout << "90_m: " << l_m.to_string() << std::endl;

    auto const l_km = 2_km;
    std::cout << "2_km: " << l_km.to_string() << std::endl;

}