#ifndef PROTORDUINO_H
#define PROTORDUINO_H

#include <Arduino.h>

typedef void (*Task)();

class Protorduino {
  private:
    uint8_t numberOfTasks;
    Task* tasks;
    bool* tasksRegistrationStatus;
    uint32_t* tasksDurations;
    uint32_t* lastExecutionTimestamps;

  public:
    Protorduino(uint8_t maxNumberOfTasks);
    void registerTask(Task task, uint32_t tasksDuration, uint8_t order);
    void loop();
};

#endif
