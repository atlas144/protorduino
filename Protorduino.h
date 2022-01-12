#ifndef PROTORDUINO_H
#define PROTORDUINO_H

#include <Arduino.h>

typedef void (*Task)();

class Protorduino {
  private:
    uint8_t numberOfTasks;
    Task* tasks;
    bool* tasksRegistrationStatus;
    unsigned long* tasksDurations;
    unsigned long* lastExecutionTimestamps;

  public:
    Protorduino(uint8_t maxNumberOfTasks);
    void registerTask(Task task, unsigned long tasksDuration, uint8_t order);
    void loop();
};

#endif
