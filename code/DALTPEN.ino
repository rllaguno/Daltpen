#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "ColorConverterLib.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_RESET);
#if (SSD1306_LCDHEIGHT != 32)
#error("Altura incorrecta, cambie en la librería de Adafruit_SSD1306.h!");
#endif

int nRojo = 0;
int nNaranja = 0;
int nAmarillo = 0;
int nVerdeLimon = 0;
int nVerde = 0;
int nVerdePrimavera = 0;
int nTurquesa = 0;
int nAzul = 0;
int nAzulRey = 0;
int nVioleta = 0;
int nMorado = 0;
int nRosa = 0;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  displayDaltpen();

  if (!tcs.begin())
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }
}
 
void loop()
{
  uint16_t clear, red, green, blue;
 
  tcs.setInterrupt(false);
  delay(60); // Tarda 50ms capturar el color
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);
 
  // Hacer rgb medición relativa
  uint32_t sum = clear;
  float r;
  float g;
  float b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
 
  // Pasar rgb a bytes
  r *= 256; g *= 256; b *= 256;
 
  // Convertir a hue con libreria 
  double hue;
  double saturation;
  double value;
  ColorConverter::RgbToHsv(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b), hue, saturation, value);
 
  // Color en display
  colordisplay(hue * 360);
  delay(750);
  
}
 
void colordisplay(double hue)
{
  if (hue < 15)
  {
    Serial.println("Rojo");
    nRojo = nRojo +1;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
  
    
    if(nRojo >= 3){
    displayRojo();
    Serial.println("Display Rojo");
    delay(5000);
    } 
  }
  
  else if (hue < 45)
  {
    Serial.println("Naranja");
    nRojo = 0;
    nNaranja = nNaranja + 1;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nNaranja >= 3){
    displayNaranja();
    Serial.println("Display Naranja");
    delay(5000);
    } 
  }

  
  else if (hue < 75)
  {
    Serial.println("Amarillo");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = nAmarillo +1;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nAmarillo >= 3){
    displayAmarillo();
    Serial.println("Display Amarillo");
    delay(5000);
  }
  }

  
  else if (hue < 105)
  {
    Serial.println("Verde Limón");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = nVerdeLimon +1;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nVerdeLimon >= 3){
    displayVerdeLimon();
    Serial.println("Display Verde Limón");
    delay(5000);  }
  }

  
  else if (hue < 135)
  {
    Serial.println("Verde");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = nVerde +1;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nVerde >= 3){
    displayVerde();
    Serial.println("Display Verde");
    delay(5000);  }
  }

  
  else if (hue < 165)
  {
    Serial.println("Verde Primavera");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = nVerdePrimavera +1;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nVerdePrimavera >= 3){
    displayVerdePrimavera();
    Serial.println("Display Verde Primavera");
    delay(5000);  }
  }

  
  else if (hue < 195)
  {
    Serial.println("Turquesa");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = nTurquesa +1;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nTurquesa >= 3){
    displayTurquesa();
    Serial.println("Display Turquesa");
    delay(5000);  }
  }

  
  else if (hue < 225)
  {
    Serial.println("Azul");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = nAzul +1;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nAzul >= 3){
    displayAzul();
    Serial.println("Display Azul");
    delay(5000);  }
  }

  
  else if (hue < 255)
  {
    Serial.println("Azul Rey");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = nAzulRey +1;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nAzulRey >= 3){
    displayAzulRey();
    Serial.println("Display Azul Rey");
    delay(5000);  }
  }

  
  else if (hue < 285)
  {
    Serial.println("Violeta");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = nVioleta +1;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();
    
    if(nVioleta >= 3){
    displayVioleta();
    Serial.println("Display Violeta");
    delay(5000);  }
  }

  
  else if (hue < 315)
  {
    Serial.println("Morado");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = nMorado +1;
    nRosa = 0;
    displayLeyendo();
    
    if(nMorado >= 3){
    displayMorado();
    Serial.println("Display Morado");
    delay(5000);  }
  }

  
  else if (hue < 345)
  {
    Serial.println("Rosa");
    nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = nRosa +1;
    displayLeyendo();
    
    if(nRosa >= 3){
    displayRosa();
    Serial.println("Display Rosa");
    delay(5000);  }  }

  
  else
  {
Serial.println("Rojo");
    nRojo = nRojo +1;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = 0;
    nMorado = 0;
    nRosa = 0;
    displayLeyendo();

    
    if(nRojo >= 3){
    displayRojo();
    Serial.println("Display Rojo");
    delay(5000);
    }   
  } 
}

void displayRojo(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30,10);
  display.println("Rojo");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  
  }

void displayNaranja(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Naranja");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

void displayAmarillo(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Amarillo");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

void displayVerdeLimon(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30,0);
  display.println("Verde");
  display.setCursor(30,12);
  display.println("Limon");
  display.println(); 
  display.display(); 
  }

void displayVerde(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Verde");
  display.setCursor(10,10);
  display.println(); 
  display.display(); 
  }

void displayVerdePrimavera(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30,0);
  display.println("Verde");
  display.setCursor(15,12);
  display.println("Primavera");
  display.println(); 
  display.display(); 
  }

void displayTurquesa(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Turquesa");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

void displayAzul(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Azul");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

void displayAzulRey(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Azul Rey");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

void displayVioleta(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Violeta");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

void displayMorado(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Morado");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

void displayRosa(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("Rosa");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

  
void displayLeyendo(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,10);
  display.println("Leyendo...");
  display.setCursor(20,20);
  display.println(); 
  display.display(); 
  }

void displayDaltpen(){
  display.clearDisplay(); 
display.setTextSize(2); 
display.setTextColor(WHITE); 
display.setCursor(20,10); 
display.println("DALTPEN");
display.setCursor(20,20); 
display.display();
delay(3000);
  }

void setDefaultColor(){
nRojo = 0;
    nNaranja = 0;
    nAmarillo = 0;
    nVerdeLimon = 0;
    nVerde = 0;
    nVerdePrimavera = 0;
    nTurquesa = 0;
    nAzul = 0;
    nAzulRey = 0;
    nVioleta = nVioleta +1;
    nMorado = 0;
    nRosa = 0;

}
