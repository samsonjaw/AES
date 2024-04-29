# AES
This repository contains a C++ implementation of:
- AES-128
  
  AES is a symmetric encryption algorithm that operates on 128-bit blocks of plaintext and keys. It consists of five main operations: Add Round Key, SubBytes, Shift Rows, and Mix Columns, along with key expansion.

The implementation contains:
- pkcs7_padding
  
  This method involves adding padding bytes that equal the number of bytes needed to reach a block size of 16. For instance, if one byte is needed, 0x01 is added; if two bytes are needed, two 0x02s are added, and so forth up to 15 bytes, which would be 0x0f. Uniquely, if the length is already a multiple of 16, an entire block of 16 bytes (0x10) is added. This ensures that during decryption, the value of the last byte indicates the number of padding bytes to remove
- ECB
  
  When encrypting data that exceeds 128 bits in length, ECB mode is one of the simplest methods to use, alongside other modes like CBC, CTR, CFB, and OFB. However, ECB is less secure because identical plaintext blocks produce identical ciphertext blocks. In ECB mode, the plaintext is divided into 128-bit segments, and each segment is encrypted independently.
- Base64 encoding/decoding
  
  Base64 encoding is used to ensure that encrypted data is not output as garbled characters.

![image](https://github.com/samsonjaw/AES/assets/114964564/adc83c16-9d78-46bd-a5f4-5e7e26090985)
my note(explanation of theory / written in Chinese)：https://hackmd.io/@samson-note/InfoSec/%2F2uEV2ydvTK6WjrcYm1DZ1A
