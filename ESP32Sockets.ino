// În acest fișier se află „include” și setările principale
// care sunt partajate între celelalte fișiere .ino
#include <WiFi.h>

#define SSID "ESP32Server"
#define PASSWORD "87654321"
#define SERVER_PORT 5000

// Protocolul pe care Serverul și Clientul îl vor folosi pentru a comunica
enum Protocol{
    PIN, // Pin that you want to change the status
    VALUE, // State to which the pin should go (HIGH = 1 ou LOW = 0)
    BUFFER_SIZE // The size of our protocol. IMPORTANT: always leave as the last of the enum
};

// Compilation directive that will tell you which file we want to be compiled
// If you want the Client.ino file to be compiled, remove or comment out the '#define' line below
// If you want the Server.ino file to be compiled, leave the '#define IS_SERVER' below uncommented
//#define IS_SERVER
