# AES
This repository is an AES-128 C++ application. It integrates several components like Base64 encoding/decoding, ECB mode encryption, and pkcs7 padding to provide a complete encryption and decryption solution.

AES is a symmetric encryption algorithm that operates on 128-bit blocks of plaintext and keys. It consists of five main operations: Add Round Key, SubBytes, Shift Rows, and Mix Columns, along with key expansion.

## Features
- ECB: When encrypting data that exceeds 128 bits in length, ECB mode is one of the simplest methods to use, alongside other modes like CBC, CTR, CFB, and OFB. However, ECB is less secure because identical plaintext blocks produce identical ciphertext blocks. In ECB mode, the plaintext is divided into 128-bit segments, and each segment is encrypted independently.
- Base64 Encoding/Decoding: Encodes encrypted data to Base64 format to ensure safe text output and decodes it for decryption.
- PKCS7 Padding: This method involves adding padding bytes that equal the number of bytes needed to reach a block size of 16. For instance, if one byte is needed, 0x01 is added; if two bytes are needed, two 0x02s are added, and so forth up to 15 bytes, which would be 0x0f. Uniquely, if the length is already a multiple of 16, an entire block of 16 bytes (0x10) is added. This ensures that during decryption, the value of the last byte indicates the number of padding bytes to remove

## Code Overview
Encryption Selection: Users can select whether to encrypt or decrypt by entering '0' for encryption and '1' for decryption.
Text Format for Encryption: Allows users to choose whether the plaintext should be in byte storage (raw text) or Base64 encoded before encryption.
Key Input: Accepts a 128-bit key required for the AES encryption/decryption process.
Base64 Handling: Automatically handles Base64 encoding for encrypted output and Base64 decoding for input to decryption.
![image](https://github.com/samsonjaw/AES/assets/114964564/adc83c16-9d78-46bd-a5f4-5e7e26090985)
Below is a snippet from main.cpp demonstrating how the program interacts with the user to perform encryption:

```cpp=
int main() {
    cout << "This program supports Base64 encoding, ECB, and pkcs7 padding\n";
    cout << "Keys are only supported at 128 bits\n";

    // Loop to continuously accept user commands
    while (1) {
        cout << "===============================Please Select a Function===============================\n";
        cout << "                               0. Encrypt\n";
        cout << "                               1. Decrypt\n";
        cout << "Enter your choice (0/1)\n";
        int en_or_de;
        cin >> en_or_de;
        // Process based on user input
        if (en_or_de == 0) { // Encryption path
            // Further interactions for setting up encryption
        } else if (en_or_de == 1) { // Decryption path
            // Further interactions for setting up decryption
        }
    }
}
```
## Building and Running
Compile and run main.cpp together with other required modules using g++:

## Contributions
Contributions to enhance functionality or improve the codebase are welcome. Please feel free to fork the repository, make your changes, and submit a pull request for review.

## other
my note(explanation of theory / written in Chinese)：https://hackmd.io/@samson-note/InfoSec/%2F2uEV2ydvTK6WjrcYm1DZ1A
