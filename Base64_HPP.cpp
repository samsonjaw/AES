#include "Base64_HPP.hpp"

using namespace std;

int sBase64[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};
string Base64_encode(string str) {
    int len = str.size();
    string res;
    res.resize((len + 2) / 3 * 4);
    int j = 0;
    for (int i = 0; i < len / 3 * 3; i += 3) {
        int bits = ((str[i] & 0xff) << 16) | ((str[i + 1] & 0xff) << 8) | (str[i + 2] & 0xff);
        res[j++] = sBase64[(bits >> 18) & 0x3f];
        res[j++] = sBase64[(bits >> 12) & 0x3f];
        res[j++] = sBase64[(bits >> 6) & 0x3f];
        res[j++] = sBase64[bits & 0x3f];
    }
    if (len % 3 == 1) {
        int bits = (str[len - 1] & 0xff) << 4;
        res[j++] = sBase64[(bits >> 6) & 0x3f];
        res[j++] = sBase64[bits & 0x3f];
        res[j++] = '=';
        res[j] = '=';
    }
    else if (len % 3 == 2) {
        int bits = (str[len - 2] & 0xff) << 10 | (str[len - 1] & 0xff) << 2;
        res[j++] = sBase64[(bits >> 12) & 0x3f];
        res[j++] = sBase64[(bits >> 6) & 0x3f];
        res[j++] = sBase64[bits & 0x3f];
        res[j] = '=';
    }
    return res;
}
unsigned char BaseValue(char c) {
    if (c > 'a' - 1) {
        return c - 'a' + 26;
    }
    else if (c > 'A' - 1) {
        return c - 'A';
    }
    else if (c > '0' - 1) {
        return c - '0' + 52;
    }
    else if (c == '+') {
        return 62;
    }
    else if (c == '/') {
        return 63;
    }
    return -1;
}
string Base64_decode(string str) {
    int len = str.size();
    string res;
    for (int i = 0; i < len - 4; i += 4) {
        res.push_back((BaseValue(str[i]) << 2) | (BaseValue(str[i + 1]) >> 4));
        res.push_back((BaseValue(str[i + 1]) << 4) | (BaseValue(str[i + 2]) >> 2));
        res.push_back((BaseValue(str[i + 2]) << 6) | (BaseValue(str[i + 3])));
    }
    res.push_back((BaseValue(str[len - 4]) << 2) | (BaseValue(str[len - 3]) >> 4));
    if (str[len - 2] != '=') {
        res.push_back((BaseValue(str[len - 3]) << 4) | (BaseValue(str[len - 2]) >> 2));
    }
    if (str[len - 1] != '=') {
        res.push_back((BaseValue(str[len - 2]) << 6) | (BaseValue(str[len - 1])));
    }
    return res;
}