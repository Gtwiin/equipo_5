/*Pines del sensor ultrasonidos HC-sr04*/
#define EchoPin 5  //A continuación, el pin donde conectamos el echo del sensor ultrasonidos HC-sr04 */
#define TriggerPin 6 //A continuación, el pin donde conectamos el trigger del sensor ultrasonidos HC-sr04 */

//Hay que tener cuidado con no poner dentro de las funciones variables con los mismos nombres que en los define 

/*A continuación se crea una función que nos devuelva la distancia leida y calculada tras disparo de onda (Sensor ultrasonidos HC-sr04) */

int ping(int TriggerPin_ping, int EchoPin_ping) {
   long duracion, distanciaCm;
   
   digitalWrite(TriggerPin_ping, LOW);  // para generar un pulso limpio ponemos a LOW 4micros 
   delayMicroseconds(4);
   digitalWrite(TriggerPin_ping, HIGH);  //generamos Trigger (disparo) de 10micros
   delayMicroseconds(10);
   digitalWrite(TriggerPin_ping, LOW);
   
   duracion = pulseIn(EchoPin_ping, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanciaCm = duracion * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanciaCm;
}
/*Fin de la funcion que devuelve la distancia ( Sensor ultrasonidos HC-Sr04)*/

void setup() {
 pinMode(TriggerPin, OUTPUT); //Parte del sensor que lanza las ondas se pone como salida
 pinMode(EchoPin, INPUT);  //Parte del sensor que recibe las ondas tras chocar se pone como entrada
 Serial.begin(9600); 
}

void loop() {
/* Llamada a la función que devuelve la distanica leida o calculada*/  
int cm = ping(TriggerPin, EchoPin);
// Si se quiere mostrar la mediada usar las proximas dos lineas de código   
   Serial.print("Distancia: ");
   Serial.println(cm); 

/*Crear una distancia que al ser igual o menor comience a frenar el coche*/

   
   delay(1000);
}
