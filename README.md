# TDA7719 Audio Processor Configuration Tool

This repository contains an Arduino sketch and a Qt widget application for configuring the TDA7719 audio processor. You can run the Qt GUI application by running 'terminal.exe'. The Arduino code receives configuration data from the Qt application via serial communication and sends it to the TDA7719 audio processor.

## Dependencies

- TDA7719 library ([https://github.com/example/tda7719-library](https://github.com/liman324/TDA7719)) - Make sure to install this library and then modifying it with our TDA7719.cpp and TDA7719.h files (if my current commits not merged yet for that library) before uploading the Arduino sketch.

## Added parts for the library: (easy to redo)

### TDA7719.cpp:
```cpp
.
.
.
TDA7719::TDA7719(){
	Wire.begin();
}

void TDA7719::sendConfig(uint8_t* data) {
    writeWire(TDA7719_INPUT, data[0]);
    writeWire(TDA7719_INPUT_2, data[1]);
    writeWire(TDA7719_MIX_SOUR, data[2]);
    writeWire(TDA7719_MIX_CONT, data[3]);
    writeWire(TDA7719_MUTE, data[4]);
    writeWire(TDA7719_SOFT_1, data[5]);
    writeWire(TDA7719_SOFT_2, data[6]);
    writeWire(TDA7719_LOUD, data[7]);
    writeWire(TDA7719_VOL, data[8]);
    writeWire(TDA7719_TRBLE, data[9]);
    writeWire(TDA7719_MIDDLE, data[10]);
    writeWire(TDA7719_BASS, data[11]);
    writeWire(TDA7719_SUB_M_B, data[12]);
    writeWire(TDA7719_ATT_LF, data[13]);
    writeWire(TDA7719_ATT_RF, data[14]);
    writeWire(TDA7719_ATT_LR, data[15]);
    writeWire(TDA7719_ATT_RR, data[16]);
    writeWire(TDA7719_ATT_SUB_L, data[17]);
    writeWire(TDA7719_ATT_SUB_R, data[18]);
    writeWire(TDA7719_TEST_1, data[19]);
    writeWire(TDA7719_TEST_2, data[20]);
}


void TDA7719::setInput(int input, int md, int input_gain, int input_conf){
.
.
.
```

### TDA7719.h:
```cpp
.
.
.
class TDA7719
{
  public:
    TDA7719();
	
	  // Direct configuration transmission (21 bytes of data array should be referenced)
		    void sendConfig(uint8_t* data);
		
     ///  Input configuration / main selector ///             
        void setInput(int input, int md, int input_gain, int input_conf); // int  0...7, 0...1, 0...1, 0...7 
.
.
.
```

## Arduino Setup

1. Connect the TDA7719 audio processor to your Arduino board using the I2C pins.
2. Modify the `PIN_SDA` and `PIN_SCL` constants in the Arduino sketch to match the I2C pins of your Arduino board.
3. Upload the Arduino sketch to your Arduino board.

## Qt Widget Application

The Qt widget application provides a graphical user interface for configuring the TDA7719 audio processor. It allows you to set register values in a meaningful way and control the audio processor's settings with just a few clicks.

### Using the Application

1. Connect the Arduino board to your computer.
2. Launch the Qt widget application by running terminal.exe
3. Select the appropriate serial port configurations in the application settings window.
4. Connect to the UART channel.
5. Open variables page by clicking (x) button on top menu.
7. Modify the register values as desired.
8. Click the "Send" button to send the configuration to the Arduino and TDA7719 audio processor.
9. Click the "Save" button to save the current configuration as a checkpoint.

## Contributing

Contributions to this project are welcome. If you find any issues or have any suggestions for improvements, please open an issue or submit a pull request.
