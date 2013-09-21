// Serial manangement variables:
const int buff = 20;
char inData[buff]; // Command string
char inChar; // Where to store the character read
byte index = 0; // Index into array; where to store the character

// `setup' routine runs at reset:
void setup() 
{
    Serial.begin(9600);
    while(!Serial);
}

void loop()
{
  Serial.println("Read-Write test");
  while(Serial.available() > 0) // Read if there is data
  {
    if(index < (buff-1)) // One less than the size of the array
    {
      inChar = Serial.read(); // Read a character
      inData[index] = inChar; // Store it
      index++; // Increment where to write next
      inData[index] = '\0'; // Null terminate the string
    }
  }
  index = 0;
  Serial.println(inData);
}
