import processing.serial.*;

Serial myPort;



String val;
int sensorVal = 0;

void setup() {
  myPort = new Serial(this, "COM9", 115200);

  
}

void draw() {
   // int a = 25;
   // int b = 5;
   // String sa = str(a);
   // String sb = str(b);
  
   //val = sa+sb;
   //println(Integer.parseInt(val));
   // // If data is available,
   // //Integer.parseInt(val);
    
    
 
   //myPort.write(Integer.parseInt(val));
   // //println("no connection");
   
   myPort.write("80");
   delay(2000);
   myPort.write("90");
   delay(2000);

}
