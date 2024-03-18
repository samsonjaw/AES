#include"AES_HPP.hpp"
#include"Base64_HPP.hpp"
#include"pkcs7_HPP.hpp"

int main() {//g++ AES.cpp main.cpp -o program

    ios_base::fmtflags original_flags = cout.flags();
    int BlockSize = 16;
    //shiftrow & invshiftrow & sub & Invsub 完成測試
    cout << "此程式支援Base64編碼與pkcs7填充\n";
    while (1) {
        cout << "此AES加密與解密程式只支援128位的密鑰\n要使用加密功能請輸入0，要使用解密功能請輸入1\n";
        int en_or_de;
        cin >> en_or_de;
        if (!en_or_de) {//en
            int textLength;

            cout << "輸入的明文以字節儲存(就是常見的1byte儲存一個)的請輸入0" << '\n';
            cout << "輸入的明文以Base64編碼的請輸入1(會先轉為字節儲存再加密)" << '\n';
            int ch_or_ba;
            cin >> ch_or_ba;

            cout << "請輸入明文\n";
           
            string tmp;
            cin.ignore();
            getline(cin, tmp);
            if (ch_or_ba) {
                tmp = Base64_decode(tmp);
            }

            pkcs7_padding(tmp, BlockSize);
            textLength = tmp.size();

            unsigned char *plaintext = new unsigned char[textLength];
            for (int i = 0; i < textLength; i++) { plaintext[i] = tmp[i]; }

            cout << "填充後的16進位 ";
            for (const auto& item : tmp) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n'; cout.flags(original_flags);

            cout << "請輸入密鑰(字節儲存128bit)\n";
            unsigned char key[16];
            getline(cin, tmp);
            for (int i = 0; i < 16; i++) { key[i] = tmp[i]; }

            unsigned char *ciphertext = new unsigned char [textLength];
            encryptECB(textLength,plaintext, key, ciphertext);


            string tt;
            tt.resize(textLength);
            for (int i = 0; i < textLength; i++) { tt[i] = ciphertext[i]; }
            cout << "密文(16進位) ";
            for (const auto& item : tt) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n'; cout.flags(original_flags);

            tt = Base64_encode(tt);
            cout << tt << "\n\n";

            delete[] plaintext;
            delete[] ciphertext;
        }
        else if (en_or_de) {//de
            int textLength;
            cout << "請輸入Base64編碼的密文\n";
            string tmp;
            cin.ignore();
            getline(cin, tmp);
            tmp = Base64_decode(tmp);

            textLength = tmp.size();
            unsigned char *ciphertext = new unsigned char[textLength];

            for (int i = 0; i < textLength; i++) {
                ciphertext[i] = tmp[i];
            }
            cout << "請輸入密鑰(字節儲存128bit)\n";
            unsigned char key[16];
            getline(cin, tmp);
            for (int i = 0; i < 16; i++) {
                key[i] = tmp[i];
            }

            unsigned char *plaintext = new unsigned char[textLength];
            decryptECB(textLength,ciphertext, key, plaintext);

            
            string tt;
            tt.resize(textLength);
            for (int i = 0; i < textLength; i++) {
                tt[i] = plaintext[i];
            }

            pkcs7_unpadding(tt);
            textLength = tt.size();

            for (const auto& item : tt) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n'; cout.flags(original_flags);

            for (int i = 0; i < textLength; i++) {
                cout << plaintext[i];
            }cout << "\n\n";

            delete[] plaintext;
            delete[] ciphertext;
        }
    }
}