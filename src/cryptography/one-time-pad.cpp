#include <string>


#define AL_LEN 26

using namespace std;

char pad[AL_LEN][AL_LEN + 1];  // the one time pad

/*
 * MODES FOR OTP:
 * 0: encrypting plaintext into ciphered text with key
 * 1: decrypting ciphered text into plaintext with key
 * 2: getting key from plaintext and ciphered text
 * 3: help menu
*/


void otp(int mode = 0) // default mode: encrypting
{

}

// makes the table for encrypting and decrypting
void make_pad() 
{
    pad[0] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 1; i < AL_LEN; i++)
    {
        // makes the next row the same as the previous but shifted
        for (int j = 0; j < AL_LEN - 1; j++) pad[i][j] = pad[i - 1][j + 1];
        pad[i][25] = pad[i - 1][0];
    }
}

// encrypts text using a key
string encrypt(const string &plaintext, const string &key)
{

}

// decrypts text using a key
string decrypt(const string &ciphertext, const string &key) 
{

}

// gets key from comparing ciphered and plain text
string make_key(const string &plaintext, const string &ciphertext)
{

}