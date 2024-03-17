#ifndef Base64_HPP
#define Base64_HPP

#include<iostream>
#include<string>

using namespace std;

extern int sBase64[64];

string Base64_encode(string str);

unsigned char BaseValue(char c);

string Base64_decode(string str);

#endif // !Base64_HPP