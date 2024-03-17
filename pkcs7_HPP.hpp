#ifndef pkcs7_HPP
#define pkcs7_HPP

#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

void pkcs7_padding(string& str, int BlockSize);

void pkcs7_unpadding(string& str);


#endif // !pkcs7_HPP
