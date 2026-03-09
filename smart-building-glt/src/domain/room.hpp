#pragma once
#include "hal/ITemperatureSensor.hpp"
#include <memory>
#include <string_view>

namespace domain {

    class Room {
    public:
        // Implements REQ-001: Target 21.0C
        static constexpr double TARGET_TEMP = 21.0;
        static constexpr double TOLERANCE = 1.0;

        Room(std::string_view name, std::shared_ptr<hal::ITemperatureSensor> sensor);

        // Run one control cycle. Returns true if heater should be ON.
        bool update(); 

        double get_last_temperature() const { return m_last_temp; }

    private:
        std::string m_name;
        std::shared_ptr<hal::ITemperatureSensor> m_sensor;
        double m_last_temp = 0.0;
    };

}
