#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "sindormir.net";
const char* password = "espaciomiscela";
/*
const String css PROGMEM ={
  "  <style>  @import url('https://fonts.googleapis.com/css?family=Press+Start+2P'); body{ background-color:white} h1{ font-family:'Press Start 2P',cursive; text-align:center; font-size:4em; font-color:red} h2{ font-family:'Press Start 2P',cursive; text-align:center; font-size:2.5em; font-color:red} section{ border:2px solid gray; text-align:center} label{ font-size:1.5em; display:block; margin-bottom:5px; margin:8%} input{ width:70%; margin-left:8%; height:100px} input.selectorColor{ border-radius:70px; width:100px; padding:20px; display:block; margin-left:45%} input[type=range]{ -webkit-appearance:none; width:60%; margin:13.8px 0; margin-left:-2%} input[type=range]:focus{ outline:none} input[type=range]::-webkit-slider-runnable-track{ width:100%; height:8.4px; cursor:pointer; box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; background:#3071a9; border-radius:1.3px; border:0.2px solid #010101} input[type=range]::-webkit-slider-thumb{ box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; border:1px solid #000; height:36px; width:16px; border-radius:3px; background:#fff; cursor:pointer; -webkit-appearance:none; margin-top:-14px} input[type=range]:focus::-webkit-slider-runnable-track{ background:#367ebd} input[type=range]::-moz-range-track{ width:100%; height:8.4px; cursor:pointer; box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; background:#3071a9; border-radius:1.3px; border:0.2px solid #010101} input[type=range]::-moz-range-thumb{ box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; border:1px solid #000; height:36px; width:16px; border-radius:3px; background:#fff; cursor:pointer} input[type=range]::-ms-track{ width:100%; height:8.4px; cursor:pointer; background:transparent; border-color:transparent; color:transparent} input[type=range]::-ms-fill-lower{ background:#2a6495; border:0.2px solid #010101; border-radius:2.6px; box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d} input[type=range]::-ms-fill-upper{ background:#3071a9; border:0.2px solid #010101; border-radius:2.6px; box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d} input[type=range]::-ms-thumb{ box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; border:1px solid #000; height:36px; width:16px; border-radius:3px; background:#fff; cursor:pointer; height:8.4px} input[type=range]:focus::-ms-fill-lower{ background:#3071a9} input[type=range]:focus::-ms-fill-upper{ background:#367ebd} footer{ margin-left:20%; align-items:center; margin-top:2em}"
  };

const String html PROGMEM ={
  "<body><header><h1>Lampara RGB</h1><h2>con ESP8266</h2></header><section><form class='' action='index.html' method='post'><label>Color e intensidad</label><input type='color' name = 'Colores' class = 'selectorColor' placeholder='Color'><input type='range' name = 'intensidad'></form></section><footer><img src='https://sindormir.net/sites/sindormir.net/files/logo-sindormir-transparente-ajustado.png'</footer></body>"
};
*/

const String css ="<HTML><head><style>  @import url(\'https://fonts.googleapis.com/css?family=Press+Start+2P\'); body{ background-color:white} h1{ font-family:\'Press Start 2P\',cursive; text-align:center; font-size:4em; font-color:red} h2{ font-family:'Press Start 2P',cursive; text-align:center; font-size:2.5em; font-color:red} section{ border:2px solid gray; text-align:center} label{ font-size:1.5em; display:block; margin-bottom:5px; margin:8%} input{ width:70%; margin-left:8%; height:100px} input.selectorColor{ border-radius:70px; width:100px; padding:20px; display:block; margin-left:45%} input[type=range]{ -webkit-appearance:none; width:60%; margin:13.8px 0; margin-left:-2%} input[type=range]:focus{ outline:none} input[type=range]::-webkit-slider-runnable-track{ width:100%; height:8.4px; cursor:pointer; box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; background:#3071a9; border-radius:1.3px; border:0.2px solid #010101} input[type=range]::-webkit-slider-thumb{ box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; border:1px solid #000; height:36px; width:16px; border-radius:3px; background:#fff; cursor:pointer; -webkit-appearance:none; margin-top:-14px} input[type=range]:focus::-webkit-slider-runnable-track{ background:#367ebd} input[type=range]::-moz-range-track{ width:100%; height:8.4px; cursor:pointer; box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; background:#3071a9; border-radius:1.3px; border:0.2px solid #010101} input[type=range]::-moz-range-thumb{ box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; border:1px solid #000; height:36px; width:16px; border-radius:3px; background:#fff; cursor:pointer} input[type=range]::-ms-track{ width:100%; height:8.4px; cursor:pointer; background:transparent; border-color:transparent; color:transparent} input[type=range]::-ms-fill-lower{ background:#2a6495; border:0.2px solid #010101; border-radius:2.6px; box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d} input[type=range]::-ms-fill-upper{ background:#3071a9; border:0.2px solid #010101; border-radius:2.6px; box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d} input[type=range]::-ms-thumb{ box-shadow:1px 1px 1px #000,0px 0px 1px #0d0d0d; border:1px solid #000; height:36px; width:16px; border-radius:3px; background:#fff; cursor:pointer; height:8.4px} input[type=range]:focus::-ms-fill-lower{ background:#3071a9} input[type=range]:focus::-ms-fill-upper{ background:#367ebd} footer{ margin-left:20%; align-items:center; margin-top:2em}</style></head>";

const String html ="<body><header><h1>Lampara RGB</h1><h2>con ESP8266</h2></header><section><form class='' action='index.html' method='post'><label>Color e intensidad</label><input type='color' name = 'Colores' class = 'selectorColor' placeholder='Color'><input type='range' name = 'intensidad'></form></section><footer><img src='https://sindormir.net/sites/sindormir.net/files/logo-sindormir-transparente-ajustado.png'</footer></body></HTML>";

ESP8266WebServer server(80);

unsigned int hexToDec(String hexString) {
  
  unsigned int decValue = 0;
  int nextInt;
  
  for (int i = 0; i < hexString.length(); i++) {
    
    nextInt = int(hexString.charAt(i));
    if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
    if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
    if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
    nextInt = constrain(nextInt, 0, 15);
    
    decValue = (decValue * 16) + nextInt;
  }
  
  return decValue;
}

//Funciones para extraer colores
void dameColores(String colores){
  String R,G,B;
  int Ri, Gi,Bi;
  //Busca el comienzo del codigo hexadecimal de color
  int firstHastag = colores.indexOf('#');
  Serial.print("Primera respuesta: ");Serial.println(firstHastag);
  
  //Extrae los colores codificados en Hexadecimal en R-G-B
  R = colores.substring(firstHastag+1, firstHastag+3);
  G = colores.substring(firstHastag+3, firstHastag+5);
  B = colores.substring(firstHastag+5, firstHastag+7);
  Serial.print("Color en Hex: ");Serial.print(R);Serial.print("-"); Serial.print(G);Serial.print("-");Serial.println(B);
  
  //Convierte los valores de color hexadecimales en decimales
  R = hexToDec(R);
  G = hexToDec(G);
  B = hexToDec(B);  
  Serial.print("Color en RGB: ");Serial.print(R);Serial.print("-"); Serial.print(G);Serial.print("-");Serial.println(B);
  
  //Transforma el String en valores integer
  Ri = R.toInt();
  Gi = G.toInt();
  Bi = B.toInt();
}

void miWeb() {
  String web = css+html;  
  server.send(200, "HTML", web);
}

void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.RSSI());


  server.on("/", miWeb);



  server.begin();
  Serial.println("HTTP server started");
}

void loop(){
  server.handleClient();
}