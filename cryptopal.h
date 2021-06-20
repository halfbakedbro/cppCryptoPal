#pragma once

#include <vector>

namespace CRYPTO
{

typedef char BYTE;

class CryptoPal {
public:
    CryptoPal(const BYTE *val) {
        hexToBytes(val);
    }
    ~CryptoPal() {}

    std::vector<uint8_t> GetHexBytes() { return _hexBytes ; }

    BYTE *toBase64 (const std::vector<uint8_t>& val);

private:
    std::vector<uint8_t> _hexBytes;

    void hexToBytes(const BYTE* val);
    int _findBytes(const BYTE* val);
    uint8_t _toByte(const BYTE& a, const BYTE& b);
    uint8_t _hexToNum(const BYTE& a);
};

}; // namespace CRYPTO

