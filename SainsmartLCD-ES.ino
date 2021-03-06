//////////////////////////////////////////////////////////////////////////////////
// Nombre: SainsmartLCD-ES.txt                                                  //
//                                                                              //
// Autor:  Sergio PL                                                            //
//         http://idielectronica.blogspot.com/                                  //
//         http://github.com/sphanlung/                                          //
//                                                                              //
// Fecha:  09-08-2014                                                           //
//                                                                              //
// Descripción: Este código fue creado para usar el módulo de LCD SainSmart     //
// de 20x4 con el Arduino Uno. Para utilizarlo necesitas reemplazar la          //
// librería LiquidCrystal_I2C con el archivo LiquidCrystal_V1.2.1.zip           //
// creado por F. Malpartida.                                                    //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

#include <Wire.h>                        // Carga librería de interfaz I2C

#include <LiquidCrystal_I2C.h>           // Carga librería de I2C para LCDs 

#define I2C_ADDR 0x27                    // Configurar dirección de I2C. 
                                         // Buscar dirección en datasheet. 
										 
//Define pines en controlador de LCD usando I2C. No cambiar.
#define BACKLIGHT_PIN 3  
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin, D5_pin,D6_pin,D7_pin);

void setup()
{
lcd.begin (20,4,LCD_5x8DOTS);            //Define tipo de pantalla LCD
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
}

// Start LCD display loop
void loop()                  
{
lcd.setBacklight(HIGH);      // Enciende luz de fondo en LCD
lcd.clear();                 // Borra caracteres en LCD
lcd.print("HELLO WORLD 1       "); // Escribe en líneas 1 a 4
lcd.print("HELLO WORLD 2       ");
lcd.print("HELLO WORLD 3       "); 
lcd.print("HELLO WORLD 4       ");
delay(1000);                 // Espera 1000 ms (1 sec)
lcd.clear();                 // Borra caracteres     
lcd.setBacklight(LOW);       // Apaga luz de fondo
delay(1000);                 // Espera 1000 ms (1 sec)
}
