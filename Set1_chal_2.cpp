#include <iostream>
#include <string>
#include "cryptopal.h"

static const CRYPTO::BYTE* hex_chars = "0123456789abcdef";

const CRYPTO::BYTE* fixedXOR(const std::vector<uint8_t>& a, const std::vector<uint8_t>& b)
{
    if(a.size() != b.size()){
        return nullptr;
    }

    std::vector<uint8_t> res;
    for(int i = 0 ; i < a.size() ; i++) {
        uint8_t temp = a[i] ^ b[i];
        res.push_back(temp);
    }

    std::string str;

    for(int i = 0 ; i < res.size() ; i++){
        auto t1 = res[i] >> 4;
        auto t2 = res[i] & 0xf;

        str.push_back(hex_chars[t1 % 16]);
        str.push_back(hex_chars[t2 % 16]);
    }

    return str.c_str();
}

int main() {

    CRYPTO::CryptoPal cp("1c0111001f010100061a024b53535009181c");
    CRYPTO::CryptoPal pc("686974207468652062756c6c277320657965");

    const CRYPTO::BYTE *result = fixedXOR(cp.GetHexBytes(), pc.GetHexBytes());

    std::cout << result << std::endl;
}