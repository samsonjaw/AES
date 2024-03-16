#include"AES_HPP.hpp"
#include"Base64_HPP.hpp"
using namespace std;

int main() {//g++ AES.cpp main.cpp -o program
    
    //shiftrow & invshiftrow & sub & Invsub 完成測試
    while (1) {
        cout << "此AES加密與解密程式只支援128位的密鑰\n要使用加密功能請輸入0，要使用解密功能請輸入1\n";
        int en_or_de;
        cin >> en_or_de;
        if (!en_or_de) {//en
            cout << "輸入的明文以字節儲存(就是常見的1byte儲存一個)的請輸入0" << '\n';
            cout << "輸入的明文以Base64編碼的請輸入1(會先轉為字節儲存再加密)" << '\n';
            int ch_or_ba;
            cin >> ch_or_ba;

            cout << "請輸入明文\n";
            unsigned char plaintext[16];
            string tmp;
            cin.ignore();
            getline(cin, tmp);
            if (en_or_de) {
                tmp = Base64_decode(tmp);
            }

            cout << "明文的16進位 ";
            for (const auto& item : tmp) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n';

            for (int i = 0; i < 16; i++) { plaintext[i] = tmp[i]; }

            cout << "請輸入密鑰(字節儲存128bit)\n";
            unsigned char key[16];
            getline(cin, tmp);
            for (int i = 0; i < 16; i++) { key[i] = tmp[i]; }

            unsigned char ciphertext[16];
            encrypt(plaintext, key, ciphertext);


            string tt;
            tt.resize(16);
            for (int i = 0; i < 16; i++) { tt[i] = ciphertext[i]; }
            cout << "密文(16進位) ";
            for (const auto& item : tt) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n';

            tt = Base64_encode(tt);
            cout << tt << "\n\n";
        }
        else if (en_or_de) {//de
            cout << "請輸入Base64編碼的密文\n";
            unsigned char ciphertext[16];
            string tmp;
            cin.ignore();
            getline(cin, tmp);
            tmp = Base64_decode(tmp);

            for (int i = 0; i < 16; i++) {
                ciphertext[i] = tmp[i];
            }
            cout << "請輸入密鑰(字節儲存128bit)\n";
            unsigned char key[16];
            getline(cin, tmp);
            for (int i = 0; i < 16; i++) {
                key[i] = tmp[i];
            }

            unsigned char plaintext[16];
            decrypt(ciphertext, key, plaintext);


            string tt;
            tt.resize(16);
            for (int i = 0; i < 16; i++) {
                tt[i] = plaintext[i];
            }
            for (const auto& item : tt) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n';

            for (int i = 0; i < 16; i++) {
                cout << plaintext[i];
            }cout << "\n\n";
        }
    }
}