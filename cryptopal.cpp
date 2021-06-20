#include "cryptopal.h"


using namespace CRYPTO;

/****************************************
 * 
 * 
 * 
 ******************************************/

static const BYTE* base64_chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789"
            "+/";

void CryptoPal::hexToBytes(const BYTE *val)
{
    int len = _findBytes(val);

    for(int i = 0 ; i < len ; i+=2){
        _hexBytes.push_back(_toByte(val[i], val[i+1]));
    }
}

BYTE* CryptoPal::toBase64(const std::vector<uint8_t>& val)
{
    int out_len = 4 * ((val.size() +2)/ 3);
    BYTE* out = new BYTE(out_len);
    BYTE* temp = out;
    int i = 0;
    for(i = 0 ; i < val.size()-2 ; i+=3){
        *temp++ = base64_chars[(val[i] >> 2) & 0x3f];
        *temp++ = base64_chars[((val[i] & 0x3) << 4) | ((val[i+1] & 0xf0) >> 4)];
        *temp++ = base64_chars[((val[i+1] & 0xf) << 2) | ((val[i+2] & 0xc0) >> 6)];
        *temp++ = base64_chars[val[i+2] & 0x3f];
    }

    if(i < val.size()) {
        *temp++ = base64_chars[(val[i] >> 2) & 0x3f];
        if(i == (val.size()-1)){
            *temp++ = base64_chars[((val[i] & 0x3) << 4)];
            *temp++ = '=';
        }else{
            *temp++ = base64_chars[((val[i] & 0x3) << 4) | ((val[i+1] & 0xf0) >> 4)];
            *temp++ = base64_chars[((val[i+1] & 0xf) << 2)];
        }
        *temp++ = '=';
    }
    *temp= '\0';

    return out;
}

int CryptoPal::_findBytes(const BYTE *val)
{
    int len = 0;

    while(*val != '\0'){
        len++;
        val++;
    }

    return len;
}

uint8_t CryptoPal::_toByte(const BYTE& a, const BYTE& b)
{
    return (_hexToNum(a) << 4) | (_hexToNum(b));
}

uint8_t CryptoPal::_hexToNum(const BYTE& a)
{
    if('0' <= a && '9' >= a)
        return a - '0';
    if('a' <= a && 'z' >= a)
        return 10 + (a - 'a');
    if('A' <= a && 'Z' >= a)
        return 10 + (a - 'A');
}