#include"AES_HPP.hpp"
#include"Base64_HPP.hpp"
#include"pkcs7_HPP.hpp"

int main() {//g++ AES.cpp main.cpp -o program

    ios_base::fmtflags original_flags = cout.flags();
    int BlockSize = 16;
    //shiftrow & invshiftrow & sub & Invsub ��������
    cout << "���{���䴩Base64�s�X�Ppkcs7��R\n";
    while (1) {
        cout << "��AES�[�K�P�ѱK�{���u�䴩128�쪺�K�_\n�n�ϥΥ[�K�\��п�J0�A�n�ϥθѱK�\��п�J1\n";
        int en_or_de;
        cin >> en_or_de;
        if (!en_or_de) {//en
            int textLength;

            cout << "��J������H�r�`�x�s(�N�O�`����1byte�x�s�@��)���п�J0" << '\n';
            cout << "��J������HBase64�s�X���п�J1(�|���ର�r�`�x�s�A�[�K)" << '\n';
            int ch_or_ba;
            cin >> ch_or_ba;

            cout << "�п�J����\n";
           
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

            cout << "��R�᪺16�i�� ";
            for (const auto& item : tmp) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n'; cout.flags(original_flags);

            cout << "�п�J�K�_(�r�`�x�s128bit)\n";
            unsigned char key[16];
            getline(cin, tmp);
            for (int i = 0; i < 16; i++) { key[i] = tmp[i]; }

            unsigned char *ciphertext = new unsigned char [textLength];
            encryptECB(textLength,plaintext, key, ciphertext);


            string tt;
            tt.resize(textLength);
            for (int i = 0; i < textLength; i++) { tt[i] = ciphertext[i]; }
            cout << "�K��(16�i��) ";
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
            cout << "�п�JBase64�s�X���K��\n";
            string tmp;
            cin.ignore();
            getline(cin, tmp);
            tmp = Base64_decode(tmp);

            textLength = tmp.size();
            unsigned char *ciphertext = new unsigned char[textLength];

            for (int i = 0; i < textLength; i++) {
                ciphertext[i] = tmp[i];
            }
            cout << "�п�J�K�_(�r�`�x�s128bit)\n";
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