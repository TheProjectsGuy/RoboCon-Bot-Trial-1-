import processing.serial.*;

Serial s;

void setup() {
  size(500,200);
  s = new Serial(this,"COM15",38400);
  s.bufferUntil('\n');
}

void draw() {
  background(0);
  textSize(20);
  textAlign(CENTER,CENTER);
  text("Press W A S or D to move and <SPACE> to stop",width/2,height/2);
}

void keyPressed() {
  s.write(key);
  println("Sending " + str(key) + " to the serial monitor");
}