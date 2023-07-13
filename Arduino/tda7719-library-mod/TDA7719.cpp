#include <Arduino.h>
#include <Wire.h>
#include "TDA7719.h"

TDA7719::TDA7719(){
	Wire.begin();
}

void TDA7719::sendConfig(uint8_t* data) {

        for (size_t i = 0; i < size; i++) {
                writeWire(i, data[i]); 
        }

}

void TDA7719::writeWire(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(TDA7719_address);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}


void TDA7719::setInput(int input, int md, int input_gain, int input_conf){
        switch (input) {    
        case  0: input = 0b00000000;break;
        case  1: input = 0b00000001;break;
        case  2: input = 0b00000010;break;
        case  3: input = 0b00000011;break;
        case  4: input = 0b00000100;break;
        case  5: input = 0b00000101;break;
        case  6: input = 0b00000110;break;
        case  7: input = 0b00000111;break;
        }
        switch (md) {
        case 0: md = 0b00000000;break;
        case 1: md = 0b00001000;break;
        }
        switch (input_gain) {
        case 0: input_gain = 0b00000000;break;
        case 1: input_gain = 0b00010000;break;
        }
        switch (input_conf) {    
        case  0: input_conf = 0b00000000;break;
        case  1: input_conf = 0b00100000;break;
        case  2: input_conf = 0b01000000;break;
        case  3: input_conf = 0b01100000;break;
        case  4: input_conf = 0b10000000;break;
        case  5: input_conf = 0b10100000;break;
        case  6: input_conf = 0b11000000;break;
        case  7: input_conf = 0b11100000;break;
        }
        int input_sum = input + md + input_gain + input_conf;
  writeWire(TDA7719_INPUT, input_sum);
}

void TDA7719::setInput_2(int sell, int md_2, int input_gain_2, int bypass_front, int bypass_rear, int bypass_sub) {
switch (sell) {    
        case  0: sell = 0b00000000;break;
        case  1: sell = 0b00000001;break;
        case  2: sell = 0b00000010;break;
        case  3: sell = 0b00000011;break;
        case  4: sell = 0b00000100;break;
        case  5: sell = 0b00000101;break;
        case  6: sell = 0b00000110;break;
        case  7: sell = 0b00000111;break;
        }
        switch (md_2) {
        case 0: md_2 = 0b00000000;break;
        case 1: md_2 = 0b00001000;break;
        }
        switch (input_gain_2) {
        case 0: input_gain_2 = 0b00000000;break;
        case 1: input_gain_2 = 0b00010000;break;
        }
        switch (bypass_front) {
        case 0: bypass_front = 0b00000000;break;
        case 1: bypass_front = 0b00100000;break;
        }
        switch (bypass_rear) {
        case 0: bypass_rear = 0b00000000;break;
        case 1: bypass_rear = 0b01000000;break;
        }
        switch (bypass_sub) {
        case 0: bypass_sub = 0b00000000;break;
        case 1: bypass_sub = 0b10000000;break;
        }
        int input_2_sum = sell + md_2 + input_gain_2 + bypass_front + bypass_rear + bypass_sub;
  writeWire(TDA7719_INPUT_2, input_2_sum);        
}

void TDA7719::setMix_source(int mix_sell, int mix_att){
        switch (mix_sell) {    
        case  0: mix_sell = 0b00000000;break;
        case  1: mix_sell = 0b00000001;break;
        case  2: mix_sell = 0b00000010;break;
        case  3: mix_sell = 0b00000011;break;
        case  4: mix_sell = 0b00000100;break;
        case  5: mix_sell = 0b00000101;break;
        case  6: mix_sell = 0b00000110;break;
        case  7: mix_sell = 0b00000111;break;
        }
        switch (mix_att) {
        case  0: mix_att = 0b00000000;break;
        case -1: mix_att = 0b00001000;break;
        case -2: mix_att = 0b00010000;break;
        case -3: mix_att = 0b00011000;break;
        case -4: mix_att = 0b00100000;break;
        case -5: mix_att = 0b00101000;break;
        case -6: mix_att = 0b00110000;break;
        case -7: mix_att = 0b00111000;break;
        case -8: mix_att = 0b01000000;break;
        case -9: mix_att = 0b01001000;break;
        case -10: mix_att= 0b01010000;break;
        case -11: mix_att= 0b01011000;break;
        case -12: mix_att= 0b01100000;break;
        case -13: mix_att= 0b01101000;break;
        case -14: mix_att= 0b01110000;break;
        case -15: mix_att= 0b01111000;break;
        case -16: mix_att= 0b10000000;break;
        case -17: mix_att= 0b10001000;break;
        case -18: mix_att= 0b10010000;break;
        case -19: mix_att= 0b10011000;break;
        case -20: mix_att= 0b10100000;break;
        case -21: mix_att= 0b10101000;break;
        case -22: mix_att= 0b10110000;break;
        case -23: mix_att= 0b10111000;break;
        case -24: mix_att= 0b11000000;break;
        case -25: mix_att= 0b11001000;break;
        case -26: mix_att= 0b11010000;break;
        case -27: mix_att= 0b11011000;break;
        case -28: mix_att= 0b11100000;break;
        case -29: mix_att= 0b11101000;break;
        case -30: mix_att= 0b11110000;break;
        case -31: mix_att= 0b11111000;break;
        }
        int mix_source_sum = mix_sell + mix_att;
        writeWire(TDA7719_MIX_SOUR, mix_source_sum);  
        }
         
void TDA7719::setMix_cont(int mix_fl, int mix_fr, int mix_rl, int mix_rr, int rear_speak, int ref_out_sell, int level_metr, int dc) {
        switch (mix_fl){
        case 0: mix_fl = 0b00000000;break;
        case 1: mix_fl = 0b00000001;break;
        }
        switch (mix_fr){
        case 0: mix_fr = 0b00000000;break;
        case 1: mix_fr = 0b00000010;break;
        }
        switch (mix_rl){
        case 0: mix_rl = 0b00000000;break;
        case 1: mix_rl = 0b00000100;break;
        }
        switch (mix_rr){
        case 0: mix_rr = 0b00000000;break;
        case 1: mix_rr = 0b00001000;break;
        }
        switch (rear_speak){
        case 0: rear_speak = 0b00000000;break;
        case 1: rear_speak = 0b00010000;break;
        }
        switch (ref_out_sell){
        case 0: ref_out_sell = 0b00000000;break;
        case 1: ref_out_sell = 0b00100000;break;
        }
        switch (level_metr){
        case 0: level_metr = 0b00000000;break;
        case 1: level_metr = 0b01000000;break;
        }
        switch (dc){
        case 0: dc = 0b00000000;break;
        case 1: dc = 0b10000000;break;
        }
        int mix_cont_sum = mix_fl + mix_fr + mix_rl + mix_rr + rear_speak +ref_out_sell +level_metr + dc;
        writeWire(TDA7719_MIX_CONT, mix_cont_sum); 
        } 
        
void TDA7719::setMute(int mute, int pin_mute, int time_mute, int sub_in_conf, int sub_eneble, int fast, int filter) {
        switch (mute){
        case 0: mute = 0b00000000;break;
        case 1: mute = 0b00000001;break;
        }
        switch (pin_mute){
        case 0: pin_mute = 0b00000000;break;
        case 1: pin_mute = 0b00000010;break;
        }
        switch (time_mute){
        case 0: time_mute = 0b00000000;break;
        case 1: time_mute = 0b00000100;break;
        case 2: time_mute = 0b00001000;break;
        case 3: time_mute = 0b00001100;break;
        }
        switch (sub_in_conf){
        case 0: sub_in_conf = 0b00000000;break;
        case 1: sub_in_conf = 0b00010000;break;
        }
        switch (sub_eneble){
        case 0: sub_eneble = 0b00000000;break;
        case 1: sub_eneble = 0b00100000;break;
        }
        switch (fast){
        case 0: fast = 0b00000000;break;
        case 1: fast = 0b01000000;break;
        }
        switch (filter){
        case 0: filter = 0b00000000;break;
        case 1: filter = 0b10000000;break;
        }
        int mute_sum = mute + pin_mute + time_mute + sub_in_conf + sub_eneble + fast + filter;
        writeWire(TDA7719_MUTE, mute_sum); 
        }    
        
        
void TDA7719::setSoft_1(int soft_loun, int soft_vol, int soft_treb, int soft_mid, int soft_bass, int soft_lf, int soft_fr, int soft_lr) {
        switch (soft_loun){
        case 0: soft_loun = 0b00000000;break;
        case 1: soft_loun = 0b00000001;break;
        }
        switch (soft_vol){
        case 0: soft_vol = 0b00000000;break;
        case 1: soft_vol = 0b00000010;break;
        }
        switch (soft_treb){
        case 0: soft_treb = 0b00000000;break;
        case 1: soft_treb = 0b00000100;break;
        }
        switch (soft_mid){
        case 0: soft_mid = 0b00000000;break;
        case 1: soft_mid = 0b00001000;break;
        }
        switch (soft_bass){
        case 0: soft_bass = 0b00000000;break;
        case 1: soft_bass = 0b00010000;break;
        }
        switch (soft_lf){
        case 0: soft_lf = 0b00000000;break;
        case 1: soft_lf = 0b00100000;break;
        }
        switch (soft_fr){
        case 0: soft_fr = 0b00000000;break;
        case 1: soft_fr = 0b01000000;break;
        }
        switch (soft_lr){
        case 0: soft_lr = 0b00000000;break;
        case 1: soft_lr = 0b00000100;break;
        }
        int soft_sum = soft_loun + soft_vol + soft_treb + soft_mid + soft_bass + soft_lf + soft_fr + soft_lr;
        writeWire(TDA7719_SOFT_1, soft_sum); 
        }
        
void TDA7719::setSoft_2(int soft_rr, int soft_sub_l, int soft_sub_r, int soft_time, int soft_zero, int soft_time_cons){
        switch (soft_rr){
        case 0: soft_rr = 0b00000000;break;
        case 1: soft_rr = 0b00000001;break;
        }
        switch (soft_sub_l){
        case 0: soft_sub_l = 0b00000000;break;
        case 1: soft_sub_l = 0b00000010;break;
        }
        switch (soft_sub_r){
        case 0: soft_sub_r = 0b00000000;break;
        case 1: soft_sub_r = 0b00000100;break;
        }
        switch (soft_time){
        case 0: soft_time = 0b00000000;break;
        case 1: soft_time = 0b00001000;break;
        }
        switch (soft_zero){
        case 0: soft_zero = 0b00000000;break;
        case 1: soft_zero = 0b00010000;break;
        case 2: soft_zero = 0b00100000;break;
        }
        switch (soft_time_cons){
        case 0: soft_time_cons = 0b00000000;break;
        case 1: soft_time_cons = 0b01000000;break;
        case 2: soft_time_cons = 0b10000000;break;
        case 3: soft_time_cons = 0b11000000;break;
        }
        int soft_2_sum = soft_rr + soft_sub_l + soft_sub_r + soft_time + soft_zero + soft_time_cons;
        writeWire(TDA7719_SOFT_2, soft_2_sum);
        }

void TDA7719::setLoudness(int loud_att, int loud_f, int loud_b, int loud_s){
        loud_att = abs(loud_att);
        switch (loud_f){
        case 0: loud_f = 0b00000000;break;
        case 1: loud_f = 0b00010000;break;
        case 2: loud_f = 0b00100000;break;
        case 3: loud_f = 0b00110000;break;
        }
        switch (loud_b){
        case 0: loud_b = 0b00000000;break;
        case 1: loud_b = 0b01000000;break;
        }
        switch (loud_s){
        case 0: loud_s = 0b00000000;break;
        case 1: loud_s = 0b10000000;break;
        }
        int loud_sum = loud_att + loud_f + loud_b + loud_s;
        writeWire(TDA7719_LOUD, loud_sum);
        }


void TDA7719::setVol(int gain, int out_gain, int soft_step){
        switch (gain){
        case -15: gain = 0b00000000;break;
        case -14: gain = 0b00000001;break;
        case -13: gain = 0b00000010;break;
        case -12: gain = 0b00000011;break;
        case -11: gain = 0b00000100;break;
        case -10: gain = 0b00000101;break;
        case -9:  gain = 0b00000110;break;
        case -8:  gain = 0b00000111;break;
        case -7:  gain = 0b00001000;break;
        case -6:  gain = 0b00001001;break;
        case -5:  gain = 0b00001010;break;
        case -4:  gain = 0b00001011;break;
        case -3:  gain = 0b00001100;break;  
        case -2:  gain = 0b00001101;break;
        case -1:  gain = 0b00001110;break;
  
        case 0:   gain = 0b00001111;break;

        case 1:   gain = 0b00011110;break;   
        case 2:   gain = 0b00011101;break;  
        case 3:   gain = 0b00011100;break;  
        case 4:   gain = 0b00011011;break;  
        case 5:   gain = 0b00011010;break;  
        case 6:   gain = 0b00011001;break;  
        case 7:   gain = 0b00011000;break;  
        case 8:   gain = 0b00010111;break;  
        case 9:   gain = 0b00010110;break;  
        case 10:  gain = 0b00010101;break;  
        case 11:  gain = 0b00010100;break;   
        case 12:  gain = 0b00010011;break;  
        case 13:  gain = 0b00010010;break;  
        case 14:  gain = 0b00010001;break;  
        case 15:  gain = 0b00010000;break;  
        }
        switch (out_gain){
        case 0: out_gain = 0b00000000;break;
        case 1: out_gain = 0b01000000;break;
        }
        switch (soft_step){
        case 0: soft_step = 0b00000000;break;
        case 1: soft_step = 0b10000000;break;
        }
        int vol_sum = gain + out_gain + soft_step;
        writeWire(TDA7719_VOL, vol_sum);
        }
        
void TDA7719::setTreble(int gain_treb, int treb_f, int soft_treb){
        switch (gain_treb){
        case -15: gain_treb = 0b00000000;break;
        case -14: gain_treb = 0b00000001;break;
        case -13: gain_treb = 0b00000010;break;
        case -12: gain_treb = 0b00000011;break;
        case -11: gain_treb = 0b00000100;break;
        case -10: gain_treb = 0b00000101;break;
        case -9:  gain_treb = 0b00000110;break;
        case -8:  gain_treb = 0b00000111;break;
        case -7:  gain_treb = 0b00001000;break;
        case -6:  gain_treb = 0b00001001;break;
        case -5:  gain_treb = 0b00001010;break;
        case -4:  gain_treb = 0b00001011;break;
        case -3:  gain_treb = 0b00001100;break;  
        case -2:  gain_treb = 0b00001101;break;
        case -1:  gain_treb = 0b00001110;break;
  
        case 0:   gain_treb = 0b00001111;break;

        case 1:   gain_treb = 0b00011110;break;   
        case 2:   gain_treb = 0b00011101;break;  
        case 3:   gain_treb = 0b00011100;break;  
        case 4:   gain_treb = 0b00011011;break;  
        case 5:   gain_treb = 0b00011010;break;  
        case 6:   gain_treb = 0b00011001;break;  
        case 7:   gain_treb = 0b00011000;break;  
        case 8:   gain_treb = 0b00010111;break;  
        case 9:   gain_treb = 0b00010110;break;  
        case 10:  gain_treb = 0b00010101;break;  
        case 11:  gain_treb = 0b00010100;break;   
        case 12:  gain_treb = 0b00010011;break;  
        case 13:  gain_treb = 0b00010010;break;  
        case 14:  gain_treb = 0b00010001;break;  
        case 15:  gain_treb = 0b00010000;break;  
        }
        switch (treb_f){
        case 0: treb_f = 0b00000000;break;
        case 1: treb_f = 0b00100000;break;
        case 2: treb_f = 0b01000000;break;
        case 3: treb_f = 0b01100000;break;
        }
        switch (soft_treb){
        case 0: soft_treb = 0b00000000;break;
        case 1: soft_treb = 0b10000000;break;
        }
        int treb_sum = gain_treb + treb_f + soft_treb;
        writeWire(TDA7719_TRBLE, treb_sum);
        }

void TDA7719::setMiddle(int gain_mid, int mid_q, int soft_mid){
        switch (gain_mid){
        case -15: gain_mid = 0b00000000;break;
        case -14: gain_mid = 0b00000001;break;
        case -13: gain_mid = 0b00000010;break;
        case -12: gain_mid = 0b00000011;break;
        case -11: gain_mid = 0b00000100;break;
        case -10: gain_mid = 0b00000101;break;
        case -9:  gain_mid = 0b00000110;break;
        case -8:  gain_mid = 0b00000111;break;
        case -7:  gain_mid = 0b00001000;break;
        case -6:  gain_mid = 0b00001001;break;
        case -5:  gain_mid = 0b00001010;break;
        case -4:  gain_mid = 0b00001011;break;
        case -3:  gain_mid = 0b00001100;break;  
        case -2:  gain_mid = 0b00001101;break;
        case -1:  gain_mid = 0b00001110;break;
  
        case 0:   gain_mid = 0b00001111;break;

        case 1:   gain_mid = 0b00011110;break;   
        case 2:   gain_mid = 0b00011101;break;  
        case 3:   gain_mid = 0b00011100;break;  
        case 4:   gain_mid = 0b00011011;break;  
        case 5:   gain_mid = 0b00011010;break;  
        case 6:   gain_mid = 0b00011001;break;  
        case 7:   gain_mid = 0b00011000;break;  
        case 8:   gain_mid = 0b00010111;break;  
        case 9:   gain_mid = 0b00010110;break;  
        case 10:  gain_mid = 0b00010101;break;  
        case 11:  gain_mid = 0b00010100;break;   
        case 12:  gain_mid = 0b00010011;break;  
        case 13:  gain_mid = 0b00010010;break;  
        case 14:  gain_mid = 0b00010001;break;  
        case 15:  gain_mid = 0b00010000;break;  
        }
        switch (mid_q){
        case 0: mid_q = 0b00000000;break;
        case 1: mid_q = 0b00100000;break;
        case 2: mid_q = 0b01000000;break;
        case 3: mid_q = 0b01100000;break;
        }
        switch (soft_mid){
        case 0: soft_mid = 0b00000000;break;
        case 1: soft_mid = 0b10000000;break;
        }
        int mid_sum = gain_mid + mid_q + soft_mid;
        writeWire(TDA7719_MIDDLE, mid_sum);
        }

void TDA7719::setBass(int gain_bass, int bass_q, int soft_bass){
        switch (gain_bass){
        case -15: gain_bass = 0b00000000;break;
        case -14: gain_bass = 0b00000001;break;
        case -13: gain_bass = 0b00000010;break;
        case -12: gain_bass = 0b00000011;break;
        case -11: gain_bass = 0b00000100;break;
        case -10: gain_bass = 0b00000101;break;
        case -9:  gain_bass = 0b00000110;break;
        case -8:  gain_bass = 0b00000111;break;
        case -7:  gain_bass = 0b00001000;break;
        case -6:  gain_bass = 0b00001001;break;
        case -5:  gain_bass = 0b00001010;break;
        case -4:  gain_bass = 0b00001011;break;
        case -3:  gain_bass = 0b00001100;break;  
        case -2:  gain_bass = 0b00001101;break;
        case -1:  gain_bass = 0b00001110;break;
  
        case 0:   gain_bass = 0b00001111;break;

        case 1:   gain_bass = 0b00011110;break;   
        case 2:   gain_bass = 0b00011101;break;  
        case 3:   gain_bass = 0b00011100;break;  
        case 4:   gain_bass = 0b00011011;break;  
        case 5:   gain_bass = 0b00011010;break;  
        case 6:   gain_bass = 0b00011001;break;  
        case 7:   gain_bass = 0b00011000;break;  
        case 8:   gain_bass = 0b00010111;break;  
        case 9:   gain_bass = 0b00010110;break;  
        case 10:  gain_bass = 0b00010101;break;  
        case 11:  gain_bass = 0b00010100;break;   
        case 12:  gain_bass = 0b00010011;break;  
        case 13:  gain_bass = 0b00010010;break;  
        case 14:  gain_bass = 0b00010001;break;  
        case 15:  gain_bass = 0b00010000;break;  
        }
        switch (bass_q){
        case 0: bass_q = 0b00000000;break;
        case 1: bass_q = 0b00100000;break;
        case 2: bass_q = 0b01000000;break;
        case 3: bass_q = 0b01100000;break;
        }
        switch (soft_bass){
        case 0: soft_bass = 0b00000000;break;
        case 1: soft_bass = 0b10000000;break;
        }
        int bass_sum = gain_bass + bass_q + soft_bass;
        writeWire(TDA7719_BASS, bass_sum);
        }
 
void TDA7719::setSMB(int sub_f, int sub_out, int mid_f, int bass_f, int bass_dc) {
        switch (sub_f){
        case 0: sub_f = 0b00000000;break;
        case 1: sub_f = 0b00000001;break;
        case 2: sub_f = 0b00000010;break;
        case 3: sub_f = 0b00000011;break;
        }
        switch (sub_out){
        case 0: sub_out = 0b00000000;break;
        case 1: sub_out = 0b00000100;break;
        }
        switch (mid_f){
        case 0: mid_f = 0b00000000;break;
        case 1: mid_f = 0b00001000;break;
        case 2: mid_f = 0b00010000;break;
        case 3: mid_f = 0b00011000;break;
        }
        switch (bass_f){
        case 0: bass_f = 0b00000000;break;
        case 1: bass_f = 0b00100000;break;
        case 2: bass_f = 0b01000000;break;
        case 3: bass_f = 0b01100000;break;
        }
        switch (bass_dc){
        case 0: bass_dc = 0b00000000;break;
        case 1: bass_dc = 0b10000000;break;
        }
        int smb_sum = sub_f + sub_out + mid_f + bass_f + bass_dc;
        writeWire(TDA7719_SUB_M_B, smb_sum);
        }

void TDA7719::setVol_LF(int lf, int soft_lf){
        lf = abs(lf)+0b00010000;
        switch (soft_lf){
        case 0: soft_lf = 0b00000000;break;
        case 1: soft_lf = 0b10000000;break;
        }
        int lf_sum = lf + soft_lf;
        writeWire(TDA7719_ATT_LF, lf_sum);
        }

void TDA7719::setVol_RF(int rf, int soft_rf){
        rf = abs(rf)+0b00010000;
        switch (soft_rf){
        case 0: soft_rf = 0b00000000;break;
        case 1: soft_rf = 0b10000000;break;
        }
        int rf_sum = rf + soft_rf;
        writeWire(TDA7719_ATT_RF, rf_sum);
        }

void TDA7719::setVol_LR(int lr, int soft_lr){
        lr = abs(lr)+0b00010000;
        switch (soft_lr){
        case 0: soft_lr = 0b00000000;break;
        case 1: soft_lr = 0b10000000;break;
        }
        int lr_sum = lr + soft_lr;
        writeWire(TDA7719_ATT_LR, lr_sum);
        }

void TDA7719::setVol_RR(int rr, int soft_rr){
        rr = abs(rr)+0b00010000;
        switch (soft_rr){
        case 0: soft_rr = 0b00000000;break;
        case 1: soft_rr = 0b10000000;break;
        }
        int rr_sum = rr + soft_rr;
        writeWire(TDA7719_ATT_RR, rr_sum);
        }

void TDA7719::setVol_SUB_L(int sl, int soft_sl){
        sl = abs(sl)+0b00010000;
        switch (soft_sl){
        case 0: soft_sl = 0b00000000;break;
        case 1: soft_sl = 0b10000000;break;
        }
        int sl_sum = sl + soft_sl;
        writeWire(TDA7719_ATT_SUB_L, sl_sum);
        }

void TDA7719::setVol_SUB_R(int sr, int soft_sr){
        sr = abs(sr)+0b00010000;
        switch (soft_sr){
        case 0: soft_sr = 0b00000000;break;
        case 1: soft_sr = 0b10000000;break;
        }
        int sr_sum = sr + soft_sr;
        writeWire(TDA7719_ATT_SUB_R, sr_sum);
        }

void TDA7719::setTest1(int x0, int x1, int x2, int x3){
        switch (x0){
        case 0: x0 = 0b00000000;break;
        case 1: x0 = 0b00000001;break;
        }
        switch (x1){
        case 0:   x1 = 0b00000000;break;
        case 1:   x1 = 0b00000010;break;
        case 2:   x1 = 0b00000100;break;
        case 3:   x1 = 0b00000110;break;
        case 4:   x1 = 0b00001000;break;
        case 5:   x1 = 0b00001010;break;
        case 6:   x1 = 0b00001100;break;
        case 7:   x1 = 0b00001110;break;
        case 8:   x1 = 0b00010000;break;
        case 9:   x1 = 0b00010010;break;
        case 10:  x1 = 0b00010100;break;
        case 11:  x1 = 0b00010110;break;
        case 12:  x1 = 0b00011000;break;  
        case 13:  x1 = 0b00011010;break;
        case 14:  x1 = 0b00011100;break;
        case 15:  x1 = 0b00011110;break;
        }
        switch (x2){
        case 0: x2 = 0b00000000;break;
        case 1: x2 = 0b00100000;break;
        }
        switch (x3){
        case 0: x3 = 0b00000000;break;
        case 1: x3 = 0b01000000;break;
        }
        int x_sum = x0 + x1 + x2 + x3;
        writeWire(TDA7719_TEST_1, x_sum);
        }

void TDA7719::setTest2(int y0, int y1, int y2, int y3){
        switch (y0){
        case 0: y0 = 0b00000000;break;
        case 1: y0 = 0b00000001;break;
        }
        switch (y1){
        case 0:   y1 = 0b00000000;break;
        case 1:   y1 = 0b00000010;break;
        }
        switch (y2){
        case 0:   y2 = 0b00000000;break;
        case 1:   y2 = 0b00000100;break;
        }
        switch (y3){
        case 0: y3 = 0b00000000;break;
        case 1: y3 = 0b00001000;break;
        case 2: y3 = 0b00010000;break;
        case 3: y3 = 0b00011000;break;
        }
        int y_sum = y0 + y1 + y2 + y3;
        writeWire(TDA7719_TEST_2, y_sum);
        }
