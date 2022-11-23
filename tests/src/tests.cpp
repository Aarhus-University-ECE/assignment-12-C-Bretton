#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C"
{
#include "duration.h"
}


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 


TEST_CASE("Duration")
{
    //creates new objects with default and set values
    Duration* d0 = new Duration(); 
    Duration* d1 = new Duration(5);
    Duration* d2 = new Duration(10);

    // d) test of getDuration
    REQUIRE(d0->getDuration() == 0);
    REQUIRE(d1->getDuration() == 5);
    REQUIRE(d2->getDuration() == 10);

    // e) test of tick 
    d0->tick();
    d1->tick();
    d1->tick();
    d2->tick();
    d2->tick();
    d2->tick();

    REQUIRE(d0->getDuration() == 1); //checks if time values are corresponding to initialized values plus the ticks
    REQUIRE(d1->getDuration() == 7);    //...
    REQUIRE(d2->getDuration() == 13);   //...
    
    // f) test of tick with argument
    d0->tick(5);
    d1->tick(4);
    d2->tick(6);

    REQUIRE(d0->getDuration() == 6);
    REQUIRE(d1->getDuration() == 11);
    REQUIRE(d2->getDuration() == 19);

    // g) test of modified tick with set alarm
    d0->setAlarm(25); //sets alarms
    d1->setAlarm(15);
    d2->setAlarm(21);

    REQUIRE(d0->tick(5) == false); //time doesnt exceed alarm
    REQUIRE(d1->tick(4) == false); //time doesnt exceed alarm
    REQUIRE(d2->tick(3) == true); //time exceeds alarm returns true
    
    // h) test of alarm setting with values greater or less than time
    Duration* a0 = new Duration();
    Duration* a1 = new Duration(5);
    Duration* a2 = new Duration(10);

    a0->setAlarm(5); //test time greater than current time
    a1->setAlarm(5); //test current time
    a2->setAlarm(5); //test time in past

    //checks when time exceeds alarm if it returns true or false
    REQUIRE(a0->tick(10) == true); //alarm triggered as alarm was set greater than the time
    REQUIRE(a1->tick(10) == false); //alarm did not trigger as it was set current time
    REQUIRE(a2->tick(10) == false); //alarm did not trigger as it was set in past time


    // i)
    //as the previous made tests still work after making checkAndUpdateAlarm
    //it demonstrates that the new checkAndUpdateAlarm method works


}