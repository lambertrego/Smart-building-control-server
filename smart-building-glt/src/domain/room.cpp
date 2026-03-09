#include "Room.hpp"
#include <iostream>
#include <format> // C++20 logging

namespace domain {

    Room::Room(std::string_view name, std::shared_ptr<hal::ITemperatureSensor> sensor)
        : m_name(name), m_sensor(std::move(sensor)) {}

    bool Room::update() {
        // Traceability: Implements REQ-001 Logic
        auto result = m_sensor->read_temperature();

        if (!result) {
            std::cerr << std::format("Error reading sensor for room: {}\n", m_name);
            return false; // Safe state: Heater OFF
        }

        m_last_temp = *result;
        
        // Hysteresis Control Logic
        if (m_last_temp < (TARGET_TEMP - TOLERANCE)) {
            return true; // Too cold, Heater ON
        } else if (m_last_temp > (TARGET_TEMP + TOLERANCE)) {
            return false; // Warm enough, Heater OFF
        }
        
        // Simple fallback (maintain previous state implementation omitted for brevity)
        return false; 
    }
}
