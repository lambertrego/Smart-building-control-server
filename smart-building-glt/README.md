# Smart-building-control-server
Goal: Building a smart system that can be used for Supervising several virtual plants ( heating, ventilation, lighting) for one or more building.




System Design Idea:

Build a Smart building control server that supervises several virtual plants.

Simulated  field devices : temeprature, humidity, occupancy sensor, boiler, fan, lights.
A controller that keeps a virtual room at a target temperature and humidity using simulated sensors and actuators, but structured like an embedded project.


system requiements:
The system shall log all sensor values at 1‑minute intervals for at least 30 days.
The system shall raise a high‑priority alarm if room temperature < 15 °C or > 30 °C.


