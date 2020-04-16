// It will only compile the code contained in this file
// if IS_SERVER is NOT defined
// (if n def, pay attention to 'n')
#ifndef IS_SERVER

// Pin we will do the reading
#define IN_PIN 33

void setup(){
    // We put the pin in reading mode
    pinMode(IN_PIN, INPUT_PULLUP);
    // We connect Access Point created
    // by the other ESP
    WiFi.begin(SSID, PASSWORD);

    // We hope to connect
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
    }
}

void loop(){ 
    // Variable that we will use to connect to the server
    WiFiClient client;
    // If you were unable to connect then we return
    if (!client.connect(WiFi.gatewayIP(), SERVER_PORT)){
        return;
    }

    // We created a buffer to place the data 
    uint8_t buffer[Protocol::BUFFER_SIZE];
    // We read the pin
    int value = digitalRead(IN_PIN);
    // We put the pin number in the buffer
    // whose status we want to send
    buffer[Protocol::PIN] = IN_PIN;
    // We put in the buffer the current state of the pin
    buffer[Protocol::VALUE] = value;
    // We send and end the connection
    client.write(buffer, Protocol::BUFFER_SIZE);
    client.flush();
    client.stop();
}
// Quit the #ifndef at the beginning of the file
#endif
