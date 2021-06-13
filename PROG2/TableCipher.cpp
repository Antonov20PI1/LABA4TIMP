#include "TableCipher.h"

TableCipher::TableCipher(const int key )
{
    this->key = key;
}

wstring TableCipher::encryptTableCipher(TableCipher key, wstring& data)
{
    const int str = ((data.size()-1)/key.key)+1;
    const int stolbci = key.key;
    int index = 0;
    const int dlinaData = data.length();
    wchar_t table[str][stolbci];

    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolbci; j++ ) {
            if (index < dlinaData) {
                table[i][j] = data[index];
                index++;
            } else {
                table[i][j] =' ';
            }
        }
    }

    index=0;
    wstring encrypt;
    for (int i = 0; i < stolbci; i++) {
        for (int j = 0; j < str; j++ ) {
            if (index <= dlinaData) {
                encrypt += table[j][i];
            }
            index++;
        }
    }
    encrypt[index] = '\0';
    return encrypt;
}

wstring TableCipher::decryptTableCipher(TableCipher key, wstring &data)
{
    const int str = ((data.size()-1)/key.key)+1;
    const int stolbci = key.key;
    int index = 0;
    const int dlinaData = data.length();
    wchar_t table[str][stolbci];

    for (int i = 0; i < stolbci; i++) {
        for (int j = 0; j < str; j++ ) {
            if (index < dlinaData) {
                table[j][i] = data[index];
                index++;
            } else {
                table[j][i] = ' ';
                index++;
            }
        }
    }
    index = 0;
    wstring decrypt;
    for(int i = 0; i < str; i++) {
        for (int j = 0; j< stolbci; j++) {
            if (index < dlinaData) {
                decrypt += table[i][j];
            }
            index++;
        }
    }
    decrypt[index] = '\0';
    return decrypt;
}
