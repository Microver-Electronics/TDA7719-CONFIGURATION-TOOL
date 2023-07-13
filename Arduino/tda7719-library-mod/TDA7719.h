// https://rcl-radio.ru/?p=62993
// liman324@yandex.ru

#ifndef TDA7719_H
#define TDA7719_H
// address 7 bit
#define TDA7719_address 0x44 // адрес HEX 88 > 0b10001000 > 7 bit = 0b1000100 = 0x44

//Sub addresses
#define TDA7719_INPUT        0b00000000 // Input Configuration / Main Source Selector
#define TDA7719_INPUT_2      0b00000001 // 2nd Source Selector / Direct Path
#define TDA7719_MIX_SOUR     0b00000010 // Mixing Source / Mixing Gain
#define TDA7719_MIX_CONT     0b00000011 // Mix Control / Level Meter / DC Offset Detector Config
#define TDA7719_MUTE         0b00000100 // Soft Mute / Others
#define TDA7719_SOFT_1       0b00000101 // Soft Step I
#define TDA7719_SOFT_2       0b00000110 // Soft Step II / DC-detector
#define TDA7719_LOUD         0b00000111 // Loudness
#define TDA7719_VOL          0b00001000 // Volume / Output Gain
#define TDA7719_TRBLE        0b00001001 // Treble
#define TDA7719_MIDDLE       0b00001010 // Middle
#define TDA7719_BASS         0b00001011 // Bass
#define TDA7719_SUB_M_B      0b00001100 // Subwoofer / Middle / Bass
#define TDA7719_ATT_LF       0b00001101 // Speaker Attenuator Left Front
#define TDA7719_ATT_RF       0b00001110 // Speaker Attenuator Right Front
#define TDA7719_ATT_LR       0b00001111 // Speaker Attenuator Left Rear
#define TDA7719_ATT_RR       0b00010000 // Speaker Attenuator Right Rear
#define TDA7719_ATT_SUB_L    0b00010001 // Subwoofer Attenuator Left
#define TDA7719_ATT_SUB_R    0b00010010 // Subwoofer Attenuator Right
#define TDA7719_TEST_1       0b00010011 // Testing Audio Processor 1
#define TDA7719_TEST_2       0b00010100 // Testing Audio Processor 2

#include <Arduino.h>
class TDA7719
{
  public:
    TDA7719();
	
	// Direct configuration transmission (21 bytes of data array should be referenced)
		void sendConfig(uint8_t* data);
		
     ///  Input configuration / main selector ///             
        void setInput(int input, int md, int input_gain, int input_conf); // int  0...7, 0...1, 0...1, 0...7 
        // IN0...IN7, MD1 MD2, 0dB 3dB, CFG0...CFG7
     
     ///   2nd Source selector / direct path ///   
        void setInput_2(int sell, int md_2, int input_gain_2, int bypass_front, int bypass_rear, int bypass_sub); // int 0...7, 0...1, 0...1, 0...1, 0...1, 0...1
        // IN0...IN7, MD1 MD2, 0dB 3dB, ON OFF, ON OFF, ON OFF
           
     ///  Mixing source / mixing gain ///   
        void setMix_source(int mix_sell, int mix_att); // int 0...7, -31...0
        // IN0...IN7, -31dB...0dB
        
     ///   Mix control / level meter / dc offset detector configure ///
        void setMix_cont(int mix_fl, int mix_fr, int mix_rl, int mix_rr, int rear_speak, int ref_out_sell, int level_metr, int dc); // all 0...1
        // ON OFF, ON OFF, ON OFF, ON OFF, DIRECT_PATH MAIN_IGNAL, 3.3V 4V, NORMAL RESET, LEVEL_METER _DC_OFFSET_DETECTOR 
      
     ///  Soft mute / others ///
        void setMute(int mute, int pin_mute, int time_mute, int sub_in_conf, int sub_eneble, int fast, int filter); // ON OFF, PIN_IIC IIC, 0.48 0.96 7.68 15.36, IN_MUX BASS_OUT, ON OFF, ON OFF       
     
     ///   SoftStep I //
        void setSoft_1(int soft_loun, int soft_vol, int soft_treb, int soft_mid, int soft_bass, int soft_lf, int soft_fr, int soft_lr); // all ON OFF 1,1,1,1,1,1,1,1
        
     ///  SoftStep II / DC detector  ///
        void setSoft_2(int soft_rr, int soft_sub_l, int soft_sub_r, int soft_time, int soft_zero, int soft_time_cons); // 1,1,1,1,0,3
     
     ///  Loudness ///
        void setLoudness(int loud_att, int loud_f, int loud_b, int loud_s);  // int -15...0, 0...3, 0...1, 0...1

     ///   Volume / output gain ///
        void setVol(int gain, int out_gain, int soft_step); // int -15...+15, 0...1, 0...1

     ///   Treble filter ///
        void setTreble(int gain_treb, int treb_f, int soft_treb); // int -15...+15, 0...3, 0...1

     ///   Treble filter ///
        void setMiddle(int gain_mid, int mid_q, int soft_mid); // int -15...+15, 0...3, 0...1

     ///   Bass filter ///
        void setBass(int gain_bass, int bass_q, int soft_bass); // int -15...+15, 0...3, 0...1

     ///   Subwoofer / middle / bass  ///
        void setSMB(int sub_f, int sub_out, int mid_f, int bass_f, int bass_dc); // int 0...3, 0...1, 0...3, 0...3, 0...1

     ///  Speaker attenuation (LF/RF/LR/RR) ///
        void setVol_LF(int lf, int soft_lf); // -79...0, 0..1
        void setVol_RF(int rf, int soft_rf);
        void setVol_LR(int lr, int soft_lr);
        void setVol_RR(int rr, int soft_rr);
     ///   Subwoofer attenuation (subwoofer L/subwoofer R)  ///
        void setVol_SUB_L(int sl, int soft_sl); // -79...+15, 0...1
        void setVol_SUB_R(int sr, int soft_sr);

     ///  Testing audio processor 1 ///
        void setTest1(int x0, int x1, int x2, int x3);
        void setTest2(int y0, int y1, int y2, int y3);


  private:
	void writeWire(char a, char b);
};
	
#endif //TDA7719_H
