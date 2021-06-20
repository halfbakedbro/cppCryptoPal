#include <iostream>
#include "cryptopal.h"

const CRYPTO::BYTE* OneByteXOR(const std::vector<uint8_t>& a, const CRYPTO::BYTE x)
{
    std::vector<uint8_t> res;

    for(int i=0; i < a.size() ; i++){
        uint8_t temp = a[i] ^ x;
        res.push_back(temp);
    }

    std::string str;

    for(int i = 0 ; i < res.size() ; i++){
        str.push_back(static_cast<CRYPTO::BYTE>(res[i]));
    }

    return str.c_str();
}

int main() {

    CRYPTO::CryptoPal cp("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");

    // TODO:: to calculate the letter frequency logic
    // for now i tried brute force(with all ASCII char) and found letter X as the key
    CRYPTO::BYTE x = 'X';
    const CRYPTO::BYTE *res = OneByteXOR(cp.GetHexBytes(), x);

    std::cout << res << std::endl;
}