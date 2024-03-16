#ifndef AES_HPP
#define AES_HPP

#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>

extern unsigned char S_BOX[256];

extern unsigned char INV_S_BOX[256];

extern unsigned char RCON[11];

extern unsigned char Mix[4][4];

extern unsigned char InvMix[4][4];

void KeyExpansion(const unsigned char* key, unsigned char* ExpandKey);

void KeyScheduleCore(unsigned char roundNumber, const unsigned char keyIn[4], unsigned char keyOut[4]);

void AddRoundKey(unsigned char state[4][4], const unsigned char RoundKey[4][4]);

void SubBytes(unsigned char state[4][4]);

void ShiftRows(unsigned char state[4][4]);

void MixColumns(unsigned char state[4][4]);

void InvSubBytes(unsigned char state[4][4]);

void InvShiftRows(unsigned char state[4][4]);

void InvMixColumns(unsigned char state[4][4]);

unsigned char G_Multi(unsigned char a, unsigned char b);

void encrypt(unsigned char* plaintext, unsigned char* key, unsigned char* output);

void decrypt(unsigned char* ciphertext, unsigned char* key, unsigned char* output);

#endif // AES_HPP