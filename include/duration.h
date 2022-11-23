#ifndef DURATION_H
#define DURATION_H


class Duration
{
private: //set private attributes
    int time; //integer time
    int alarm; //integer alarm
    bool alarmHasBeenSet; //bool alarmHasBeenSet

    bool checkAndUpdateAlarm(); //function to check alarm

public:
    Duration(); //constructor, initializes the instance of the object
    ~Duration(); //destructor, frees the object
    
    int getDuration(); //function to get duration

    Duration(int t); //constructor
    
    bool tick(); //tick function with no argument

    bool tick(int dt); //tick function with integer arguement

    void setAlarm(int t); //set alarm function

};


#endif // DURATION_H