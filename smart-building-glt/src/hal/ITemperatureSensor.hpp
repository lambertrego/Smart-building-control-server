#pragma once
#include <expected>
#include <system_error>

namespace hal {

    // Pure virtual interface mimicking a driver
    struct ITemperatureSensor {
        virtual ~ITemperatureSensor() = default;
        
        // Returns temperature in Celsius or an error code
        virtual std::expected<double, std::errc> read_temperature() const noexcept = 0;
    };

}
