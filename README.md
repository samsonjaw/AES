# AES
This repository is an AES-128 C++ application. It integrates several components like Base64 encoding/decoding, ECB mode encryption, and pkcs7 padding to provide a complete encryption and decryption solution.

AES is a symmetric encryption algorithm that operates on 128-bit blocks of plaintext and keys. It consists of five main operations: Add Round Key, SubBytes, Shift Rows, and Mix Columns, along with key expansion.

## Features
- **ECB**: When encrypting data that exceeds 128 bits in length, ECB mode is one of the simplest methods to use, alongside other modes like CBC, CTR, CFB, and OFB. However, ECB is less secure because identical plaintext blocks produce identical ciphertext blocks. In ECB mode, the plaintext is divided into 128-bit segments, and each segment is encrypted independently.
- **Base64 Encoding/Decoding**: Encodes encrypted data to Base64 format to ensure safe text output and decodes it for decryption.
- **PKCS7 Padding**: This method involves adding padding bytes that equal the number of bytes needed to reach a block size of 16. For instance, if one byte is needed, 0x01 is added; if two bytes are needed, two 0x02 are added, and so forth up to 15 bytes, which would be 0x0f. Uniquely, if the length is already a multiple of 16, an entire block of 16 bytes (0x10) is added. This ensures that during decryption, the value of the last byte indicates the number of padding bytes to remove

## Usage
- Compile and run main.cpp together with other required modules using g++:
- Select a Function:
When prompted, choose either encryption (0) or decryption (1):
```markdown
===============================請選擇功能===============================
                           0. encrypt加密
                           1. decrypt解密
輸入你的選擇(0/1)
```
### Encryption
- Choose Plaintext Format:
Choose how you want to input the plaintext. You can input as regular byte storage(raw text) or Base64 encoded text which will be converted to byte storage before encryption:
```markdown
===============================明文格式=================================
                           0. 字節儲存(常見的1byte儲存一個)
                           1. Base64編碼(會先轉為字節儲存再加密)
輸入你的選擇(0/1)
```
- Input the Plaintext:
Enter your plaintext as instructed. If Base64 option was selected, the input will be decoded first.
- Input the Key:
Enter a 128-bit key for the encryption. Ensure the key is exactly 16 bytes long.
- View Encrypted Result:
The program will display the encrypted text in hexadecimal format and then in Base64 encoded format.
### Decryption
- Input the Encrypted Text:
Enter the encrypted text in Base64 format, which will be decoded to byte storage format.
- Input the Key:
Enter the same 128-bit key used during encryption.
- View Decrypted Result:
The program will display the decrypted text in hexadecimal format first and then in plaintext.
## Notes
Always ensure that the key length is exactly 16 bytes.
The input for encryption can be in plain byte storage or Base64 encoded form, but decryption only accepts Base64 encoded input.

## Example
![image](https://github.com/samsonjaw/AES/assets/114964564/adc83c16-9d78-46bd-a5f4-5e7e26090985)

## Contributing
Contributions are welcome!

You can help by:

- Reporting issues
- Suggesting improvements
- Adding new features through pull requests

## License
This project is licensed under the MIT License.

## other
my note(explanation of theory / written in Chinese)：https://hackmd.io/@samson-note/InfoSec/%2F2uEV2ydvTK6WjrcYm1DZ1A
