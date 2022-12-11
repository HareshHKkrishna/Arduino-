int ldrPin1 = A0;

int threshold1 = 150;

int count=0;

int timesTosend=1;

char ph_no[]="**********";
  
void setup()
{
  Serial.begin(9600);
  delay(2000);
  Serial.println("AT+CMGF=1"); // set GSM to text mode
  delay(200);
}
void loop()
{
  int data1= analogRead(ldrPin1);// to read values obtained by the ldr1
  Serial.println("");
  Serial.print("Light Sensor 1");
  Serial.print(" Value = ");
  Serial.print(data1);
  if(data1 <= threshold1)
  { 
    while(count<timesTosend)
	  {
	  delay(1500);
   	  Serial.println(" ");
	  Serial.print("\AT+CMGS=\"");// to send the SMS
          Serial.print(ph_no);
          Serial.println("\"");
	    while(Serial.read()!='>');
		    {
		      Serial.print("SUB STATION : TONDIARPET \r STATUS : NO POWER SUPPLY ");
                     delay(500);
		     Serial.write(0x1A); // sends ctrl+z end of message
		     Serial.write(0x0D); // Carriage Return in Hex
		     Serial.write(0x0A); //line feed in Hex
		    delay(5000);
		    }
	  count++;
   	  exit(0);
	  }
  }
  else
  {
    
  }
}
