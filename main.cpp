#include"AES_HPP.hpp"
#include"Base64_HPP.hpp"
using namespace std;

int main() {//g++ AES.cpp main.cpp -o program
    
    //shiftrow & invshiftrow & sub & Invsub ��������
    while (1) {
        cout << "��AES�[�K�P�ѱK�{���u�䴩128�쪺�K�_\n�n�ϥΥ[�K�\��п�J0�A�n�ϥθѱK�\��п�J1\n";
        int en_or_de;
        cin >> en_or_de;
        if (!en_or_de) {//en
            cout << "��J������H�r�`�x�s(�N�O�`����1byte�x�s�@��)���п�J0" << '\n';
            cout << "��J������HBase64�s�X���п�J1(�|���ର�r�`�x�s�A�[�K)" << '\n';
            int ch_or_ba;
            cin >> ch_or_ba;

            cout << "�п�J����\n";
            unsigned char plaintext[16];
            string tmp;
            cin.ignore();
            getline(cin, tmp);
            if (en_or_de) {
                tmp = Base64_decode(tmp);
            }

            cout << "���媺16�i�� ";
            for (const auto& item : tmp) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n';

            for (int i = 0; i < 16; i++) { plaintext[i] = tmp[i]; }

            cout << "�п�J�K�_(�r�`�x�s128bit)\n";
            unsigned char key[16];
            getline(cin, tmp);
            for (int i = 0; i < 16; i++) { key[i] = tmp[i]; }

            unsigned char ciphertext[16];
            encrypt(plaintext, key, ciphertext);


            string tt;
            tt.resize(16);
            for (int i = 0; i < 16; i++) { tt[i] = ciphertext[i]; }
            cout << "�K��(16�i��) ";
            for (const auto& item : tt) {
                cout << hex << setw(2) << setfill('0') << (0xFF & static_cast<unsigned int>(item)) << ' ';
            }cout << '\n';

            tt = Base64_encode(tt);
            cout << tt << "\n\n";
        }
        else if (en_or_de) {//de
            cout << "�п�JBase64�s�X���K��\n";
            unsigned char ciphertext[16];
            string tmp;
            cin.ignore();
            getline(cin, tmp);
            tmp = Base64_decode(tmp);

            for (int i = 0; i < 16; i++) {
                ciphertext[i] = tmp[i];
            }
            cout << "�п�J�K�_(�r�`�x�s128bit)\n";
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