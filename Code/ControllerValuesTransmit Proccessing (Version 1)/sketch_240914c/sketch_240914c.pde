import org.gamecontrolplus.ControlIO;
import org.gamecontrolplus.ControlDevice;
import org.gamecontrolplus.Configuration;
import net.java.games.input.*; 

ControlIO control; // declaring control object
ControlDevice controller; // declaring controller values object

void setup() {
  size(300, 300);
  control = ControlIO.getInstance(this); // control system object applies for selected controller profile
  controller = control.getMatchedDevice("cont"); // sel;ecting the cont file from data folder and injecting into controller object to be used throughout code

  if (controller == null) { // If no controller is found/ no controller file is found then print message and exit program
    println("No controller found");
    exit();
  }
}

void draw() {
  background(0);
  float lJoystickY = map(controller.getSlider("leftStickVert").getValue(), -1, 1, -5, 5); // grabbing certain cont value from object and them mapping into suitable units
  float rJoystickY = map(controller.getSlider("rightStickVert").getValue(), -1, 1, -5, 5);// grabbing certain cont value from object and them mapping into suitable units
  float r2 = map(controller.getSlider("r2").getValue(), -1, 1, 0, 100);// grabbing certain cont value from object and them mapping into suitable units
  float l1 = map(controller.getButton("l1").getValue(), 0, 8, 0, 1);// grabbing certain cont value from object and them mapping into suitable units
  float r1 = map(controller .getButton("r1").getValue(), 0, 8, 0, 1);// grabbing certain cont value from object and them mapping into suitable units
  float circle = map(controller.getButton("circle").getValue(), 0, 8, 0, 1);// grabbing certain cont value from object and them mapping into suitable units
  float square = map(controller.getButton("square").getValue(), 0, 8, 0, 1);// grabbing certain cont value from object and them mapping into suitable units
  

  println(r2); // test print
}
