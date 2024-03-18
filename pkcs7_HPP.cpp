#include"pkcs7_HPP.hpp"
using namespace std;
void pkcs7_padding(string& str, int BlockSize) {
	int PaddingSize = BlockSize - (str.size() % BlockSize);
	unsigned char PaddingChar = (unsigned char)PaddingSize;
	for (int i = 0; i < PaddingSize; i++) {
		str.push_back(PaddingChar);
	}

	return;
}

void pkcs7_unpadding(string& str) {
	int PaddingSize = (int)((unsigned char)str[str.size() - 1]);
	str.resize(str.size() - PaddingSize);
	return;
}