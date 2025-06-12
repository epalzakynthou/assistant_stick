#define TRIGGER 5
#define ECHO 6
#define BUZZER 9
 
// Δήλωση Σταθερών
const float speed = 34300.0; // Ταχύτητα ήχου σε cm/s
const float distance1 = 60.0;
const float distance2 = 30.0;
const float distance3 = 10.0;
 
void setup() {
  // Ξεκινάμε την σειριακή οθόνη
  Serial.begin(9600);
 
  //Λειτουργία εισόδου/εξόδου των ακίδων
  
  
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(BUZZER, OUTPUT);
 
  
 
}
 
void loop() {
  // Ετοιμάζουμε τον αισθητήρα υπερήχων
  iniciarTrigger();
 
  // παίρνουμε την απόσταση
  float distance = calculateDistance();
 
  
 
  // Εκπέμπουμε ειδοποίηση εάν βρισκόμαστε εντός της εμβέλειας κινδύνου
  if (distance <distance1)
  {
    
    alert(distance);
  }
 
}
 

 
// Συνάρτηση που ελέγχει εάν πρέπει να ενεργοποιηθεί κάποια  ηχητική ειδοποίηση
void alert(float distance)
{
  if (distance < distance1 && distance >= distance2)
  {
    
    tone(BUZZER, 2000, 200);
  }
  else if (distance <distance2 && distance > distance3)
  {
    
    
    tone(BUZZER, 2500, 200);
  }
  else if (distance <= distance3)
  {
    
    
    tone(BUZZER, 3000, 300);
  }
}
 

float calculateDistance()
{
  unsigned long tiempo = pulseIn(ECHO, HIGH);
 
  float distance= tiempo * 0.000001 * speed / 2.0;
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  delay(500);
 
  return distance;
}
 
// Συνάρτηση που ξεκινά την ακολουθία ενεργοποίησης για να ξεκινήσει η μέτρηση
void iniciarTrigger()
{
  
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
 
  
  digitalWrite(TRIGGER, LOW);
}
