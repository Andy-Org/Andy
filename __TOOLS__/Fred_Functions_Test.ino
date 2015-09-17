/*
 *
 * Teaching myself how to write functions.
 *
 * I had to add "boolean" to the beginning of each function code
 * Next, I have a function where we pass values through it!
 * BTW, the "void" or "boolean" at the beg. of a function is the Function RETURN Type
 * eg, "VOID" means nothing to return, "INT" means return an integer.
 *
 */


void setup() {

  // Start Serial debugger
  Serial.begin(9600);
  // Debug ready mode
  Serial.println("System Ready");


}

void loop() {

  // Call first function
  connMe();

  // Wait 2 seconds
  delay(2000);

  // Setup and call 2nd function

  int a = 4;
  int b = 5;
  int x;

  x = multiFunction(a, b);
  Serial.print("a X b = ");
  Serial.println(x);
  delay(500);


}

// 1st Function
boolean connMe(){
  Serial.println("This is Conn Me function, biatch");
}

// 2nd Function
int multiFunction(int a, int b){
  int result;
  result = a * b;
  return result;
}

