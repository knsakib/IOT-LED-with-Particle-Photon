int led1 = D0;
int led2 = D1;



void setup()
{

   // Here's the pin configuration
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);

   // We are also going to declare two Spark.function(s) so that we can turn the LED on and off from the cloud.
   Spark.function("led1",led1Toggle);
   Spark.function("led2",led2Toggle);
   // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

   // For good measure, let's also make sure both LEDs are off when we start:
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);

}

// Since we're waiting for input through the cloud,
// we don't actually need to put anything in the loop

void loop()
{
   // Nothing to do here
}

// We're going to have two functions for our two leds that get called when a matching API request is sent
// This is the led1Toggle and led2Toggle function we registered to the "led" Spark.function earlier.


int led1Toggle(String command) {
    /* Spark.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will turn the LED on and telling it "off" will turn the LED off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 for the LEDs turning on, 0 for the LEDs turning off,
    and -1 if we received a totally bogus command that didn't do anything to the LEDs.
    */

    if (command=="on") {
        digitalWrite(led1,HIGH);
    
        return 1;
    }
    else if (command=="off") {
        digitalWrite(led1,LOW);
        
        return 0;
    }
    else {
        return -1;
    }
}

int led2Toggle(String command) {
   if (command=="on") {
        
        digitalWrite(led2,HIGH);
        return 1;
    }
    else if (command=="off") {
        
        digitalWrite(led2,LOW);
        return 0;
    }
    else {
        return -1;
    }
}
