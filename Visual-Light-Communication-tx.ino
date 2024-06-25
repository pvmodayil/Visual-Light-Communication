// Initialise
////////////////////////////////
#define LED_PIN LED_BUILTIN // use the built in LED
#define PERIOD 15 // in ms: period between each character of the string sent as 8-bit

String message = "Warning";
int string_length;
int converted_bit;

// setup pinmode
//////////////////////////////////
void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  //pinMode(BUTTON_PIN, INPUT_PULLUP);
  string_length = message.length();
}

// main loop of the program
//////////////////////////////////
void loop() 
{ 
  Serial.println("Start String Transmission......");
  // print the string
  Serial.println("Message: "+ message);
  for(int i = 0; i < string_length; i ++)
  {
    convert_to_byte(message.charAt(i));
  }
  Serial.println("End String Transmission......");
  delay(3000);
}


// function to convert character to byte 
void convert_to_byte(char my_byte)
{
  Serial.println("Start Character Transmission: " + String(my_byte));
  digitalWrite(LED_PIN, LOW); // start transmission
  delay(PERIOD);

  //transmission of bits
  for(int i = 0; i < 8; i++)
  { // take the left shift of 1 in hex, then bitwise and on character, comapre with zero for HIGH or LOW

    converted_bit = (my_byte&(0x01 << i))? 1 : 0; 
    Serial.println(String(converted_bit));
    digitalWrite(LED_PIN, converted_bit);
    delay(PERIOD);
  }

  digitalWrite(LED_PIN, HIGH); // end transmission
  delay(PERIOD);
  Serial.println("End Character Transmission....");
}