
// Va compila  codul conținut în acest fișier
// doar dacă IS_SERVER este definit
#ifdef IS_SERVER


// Creați serverul în portul definit de „SERVER_PORT”
WiFiServer server(SERVER_PORT);

void setup()
{
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  WiFi.begin(SSID, PASSWORD);

    // We hope to connect
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
// Puneți acest ESP ca punct de acces
    WiFi.mode(WIFI_AP);
    SSID and Password to connect to this ESP
    WiFi.softAP(SSID, PASSWORD);
    // Start the server
    server.begin();
}
void loop()
{
    // Verificați dacă există clienți care se conectează
    WiFiClient client = server.available();
    if (client) 
    {      
        // Dacă clientul are date pe care dorește să ni le trimită
        if (client.available())
        {
            
            // Am creat un buffer pentru plasarea datelor
            uint8_t buffer[Protocol::BUFFER_SIZE];
            
            // Am introdus datele trimise de client în buffer
            int len = client.read(buffer, Protocol::BUFFER_SIZE);
            
            // Verificăm ce pin a trimis clientul
            int pinNumber = buffer[Protocol::PIN];
            // Verificăm valoarea acestui pin
            int value = buffer[Protocol::VALUE];
            // Am pus pinul în modul de ieșire
            pinMode(pinNumber, OUTPUT);
            // Am schimbat starea pinului la valoarea trecută
            digitalWrite(pinNumber, value);
        }

        // Închide conexiunea cu clientul
        client.stop();
    }
}
// Ieșiți din #ifdef la începutul fișierului
#endif
