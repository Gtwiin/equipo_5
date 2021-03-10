/*Archivo de prueba del motor*/
void setup() 
{
  pinMode(8, OUTPUT); /*Configuro el pin de rotación horaria como salida*/
  pinMode(7, OUTPUT); /*Lo mismo con el pin de rotación antihoraria*/
  pinMode(5, OUTPUT); /*Lo mismo con el pin de velocidad del motor*/
  pinMode(6, OUTPUT); /*Lo mismo con el pin de activación del motor*/
}

void loop()
{
  digitalWrite(6, HIGH); /*Activo el motor*/
  digitalWrite(8, HIGH); /*Pongo el motor a girar en sentido horario poniendo el pin 8 en HIGH y el 7 en LOW*/
  digitalWrite(7, LOW);
  analogWrite(5,80); /*Pongo como salida analógica la velocidad por el pin 5 Cuidado al subirlo por encima de 150 porque podría estar pasando de los 7V del motor, hay que investigarlo*/
  /*La velocidad del motor es un número comprendido entre 0 y 255 que se envía a la monster mediante un Pin analógico*/
}
