int ldrPin1 = A0;
int ldrPin2= A1;
int ldrPin3= A4;
int ldrPin4= A5;

int threshold1 = 150;
int threshold2 = 200;
int threshold3 = 200;
int threshold4 = 200;

int count=0;

int timesTosend=1;

char ph_no[]="7299391237";
  
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
  int data2 = analogRead(ldrPin2);// to read values obtained by the ldr2
  Serial.println("");
  Serial.print("Light Sensor 2");
  Serial.print(" Value = ");
  Serial.print(data2);
  int data3 = analogRead(ldrPin3);
  Serial.println("");
  Serial.print("Light Sensor 3");// to read values obtained by the ldr3
  Serial.print(" Value = ");
  Serial.print(data3);
  int data4 = analogRead(ldrPin4);
  Serial.println("");
  Serial.print("Light Sensor 4");// to read values obtained by the ldr4
  Serial.print(" Value = ");
  Serial.print(data4);
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
		count++;;
    exit(0);
	  }
  }
  if(data2 <= threshold2)
  {
     
    while(count<timesTosend)
	  {
		delay(1500);
		Serial.println("\"");
    Serial.println(" ");
		Serial.print("\AT+CMGS=\"");
    Serial.print(ph_no);
    Serial.println("\"");
		  while(Serial.read()!='>');
		    {
			    Serial.print("FAULT LOCATION: TONDAIARPET TRANSFORMER NUMBER 1  \r STATUS : NO POWER SUPPLY \r FAULT DISTANCE : 5km ");
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
  if(data3 <=threshold3)
  {
     
    while(count<timesTosend)
	  {
		delay(1500);
		Serial.print("AT+CMGS=\"");
		Serial.print(ph_no);
		Serial.println("\"");
		  while(Serial.read()!='>');
		    {
			    Serial.print("FAULT LOCATION: TONDIARPET E.BOX_1 \r STATUS: NO POWER SUPPLY \r FAULT DISTANCE: 5.5 km");
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
  if(data4 <=threshold4)
  {
     
    while(count<timesTosend)
	  {
		delay(1500);
    Serial.println(" ");
		Serial.print("\AT+CMGS=\"");
    Serial.print(ph_no);
    Serial.println("\"");
		  while(Serial.read()!='>');
		    {
			    Serial.print("FAULT LOCATION: TONDIARPET E.BOX_2 \r STATUS: NO POWER SUPPLY \r FAULT DISTANCE: 6 km");
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
