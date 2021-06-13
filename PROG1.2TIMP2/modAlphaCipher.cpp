#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(const wstring& skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(getValidKey(skey));
}
wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    vector<int> work = convert(getValidText(open_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    vector<int> work = convert(getValidText(cipher_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline vector<int> modAlphaCipher::convert(const wstring& s)
{
    vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& v)
{
    wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
inline wstring modAlphaCipher::getValidKey(const wstring & s)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    if (s.empty())
        throw CipherError("вы ввели пустой ключ.");
    wstring tmp = s;
    for (size_t  i = 0; i< tmp.length(); i++) {
        if (!iswalpha(tmp[i]))
            throw CipherError(string("вы ввели ключ, в котором используются недопустимые символы."));
        if (iswlower(tmp[i]))
            tmp[i] = towupper(tmp[i]);
    }
    return tmp;
}

inline wstring modAlphaCipher::getValidText(const wstring & s)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    if (s.empty())
        throw CipherError("вы ввели пустую строку.");
    wstring tmp = s;
    for (size_t  i = 0; i< tmp.length(); i++) {
        if (!iswalpha(tmp[i]))
            throw CipherError(string("вы ввели строку, в которой используются недопустимые символы."));
        if (iswlower(tmp[i]))
            tmp[i] = towupper(tmp[i]);
    }
    return tmp;
}