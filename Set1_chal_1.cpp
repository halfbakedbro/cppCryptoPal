#include <iostream>
#include "cryptopal.h"

int main_dummy() {

    CRYPTO::CryptoPal cp("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");

    auto val = cp.GetHexBytes();

    CRYPTO::BYTE *value = cp.toBase64(val);

    std::cout << value << std::endl;
    
    return 0;
}