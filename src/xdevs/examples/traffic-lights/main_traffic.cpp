#include "TrafficLights.h"
#include "../../core/simulation/Coordinator.h"

int main() {
  TrafficLights tl("TrafficLights");
  Coordinator coordinator(&tl);
  coordinator.initialize();
  coordinator.simulate(432000.0);
  coordinator.exit();
  return 0;
}
