#include "Protorduino.h"

Protorduino::Protorduino(uint8_t numberOfTasks) : numberOfTasks(numberOfTasks) {
    tasks = new Task[numberOfTasks];
    tasksRegistrationStatus = new bool[numberOfTasks];
    tasksDurations = new unsigned long[numberOfTasks];
    lastExecutionTimestamps = new unsigned long[numberOfTasks];

    for (uint8_t i = 0; i < numberOfTasks; i++) {
        tasksRegistrationStatus[i] = false;
    }
}

void Protorduino::registerTask(Task task, unsigned long tasksDuration, uint8_t order) {
    order--;

    tasks[order] = task;
    tasksRegistrationStatus[order] = true;
    tasksDurations[order] = tasksDuration;
    lastExecutionTimestamps[order] = 0;
}

void Protorduino::execute() {
    for (uint8_t i = 0; i < numberOfTasks; i++) {
        if (tasksRegistrationStatus[i] == true) {
            unsigned long currentTimestamp = millis();

            if (lastExecutionTimestamps[i] + tasksDurations[i] <= currentTimestamp) {
                tasks[i]();
                
                lastExecutionTimestamps[i] = currentTimestamp;
            }
        }
    }
}
