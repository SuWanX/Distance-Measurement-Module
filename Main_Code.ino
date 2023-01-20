int trig = 2;      //Declare the value of trig(Sends ultrasonic sound waves) to pin no 8.
int echo = 3;      //Declare the value of echo(Give time that ultrasonic waves took to travel and go back to sensor) to pin no 9.
int time = 0;      //Declare the value of time be zero at first.
int distance = 0;  //Declare the value of distance be zero at first.

void setup()  //Setup Code
{
  Serial.begin(9600);     //establishes serial communication between your Arduino board and device.
  pinMode(trig, OUTPUT);  //Configures the trig pin to behave as an output.
  pinMode(echo, INPUT);   //Configures the echo pin to behave as an input.
}

void loop()  //Main Code
{
  digitalWrite(trig, HIGH);       //Sends High Signal to trig
  delayMicroseconds(10);          //Wait 10 milisecons after sending high signal to trig
  digitalWrite(trig, LOW);        //Sends Low Signal to trig
  time = pulseIn(echo, HIGH);     //Set the value of time to how many pulse signal is generated during high and low signal is sent.
  distance = (time * 0.034) / 2;  // Set distance to half number of product of time and speed of sound.

  Serial.println("Distance = ");
  Serial.println(distance);  //Print distance to the Screen
  delay(800);                //After finishing the task wait 800 milisecond and then again loop will run.
}