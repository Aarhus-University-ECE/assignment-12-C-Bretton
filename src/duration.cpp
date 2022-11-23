
#include "duration.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// 1) a) getDuration returns time of the object
int Duration::getDuration()
{
    return time;
}

// 1) b) //sets default values for time, alarm and alarmHasBeenSet
Duration::Duration(){

    time = 0;
    alarm = 0;
    alarmHasBeenSet = false;
}

// 1) c) //sets initial time with argument int t, and default alarm + alarmHasBeenSet
Duration::Duration(int t){
    assert(t >= 0); //asserts that the initial time t is greater or equal to 0
    time = t;
    alarm = 0;
    alarmHasBeenSet = false;
}

// 1) e) //tick function adds 1 to the time value, and checks the alarm
bool Duration::tick(){

    time = time + 1;

    return checkAndUpdateAlarm(); //returns checkAndUpdateAlarm, to check if alarm is triggered.
}

// 1) f) //tick function with argument int dt, to add dt to the time. returns checkAndUpdateAlarm
bool Duration::tick(int dt){

    assert(dt > 0);
    time = time + dt;

    return checkAndUpdateAlarm(); 

}

// 1) g) h) //setAlarm, if the alarm value int t is larger than the time, set the alarm
void Duration::setAlarm(int t){
    
    if(t > time){
        alarm = t; //alarm set to value int t
        alarmHasBeenSet = true; //alarm has been set is true
    }

}

// 1) i) //checks if time exceeds alarm, if alarmHasBeenSet is true and time value exceeds alarm value, return true, else return false
bool Duration::checkAndUpdateAlarm(){

    if(alarmHasBeenSet == true && time > alarm){
        alarm = 0;
        alarmHasBeenSet = false;
        return true;
    }
    else{
        return false;
    }
}

Duration::~Duration(){}; //destructor
