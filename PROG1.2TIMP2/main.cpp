#include <iostream>
#include <codecvt>
#include "modAlphaCipher.h"

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    bool end = false;
    wstring rejim, wstr,wKey;
    cout << "Добро пожаловать в программу!" << endl;
    cout << "1 - режим шифрования шифром  русскоязычных сообщений методом Гронсвельда.\n";
    cout << "2 - режим расшифрования шифра  русскоязычных сообщений методом Гронсвельда.\n";
    cout << "exit - завершить работу программы.\n";
    cout << "Результат шифрования или расшифрования выводится в виде строки прописных букв русского алфавита.\n";
    do {
        cout << "Выберите режим работы: ";
        wcin >> rejim;
        if (rejim == L"1") {
            cout << "Введите строку для шифрования: ";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ: ";
            getline(wcin,wKey);
            try {
                modAlphaCipher a(wKey);
                wstring cipher = a.encrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(cipher)<<endl;
            } catch (const CipherError & error) {
                cout << "Ошибка: " << error.what() << endl;
            }
        } else if (rejim == L"2") {
            cout << "Введите строку для расшифрования: ";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ: ";
            getline(wcin,wKey);
            try {
                modAlphaCipher b(wKey);
                wstring Text = b.decrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(Text)<<endl;
            } catch (const CipherError & error) {
                cout << "Ошибка: " <<  error.what() << endl;
            }
        } else if (rejim == L"exit") {
            cout << "До свидания!" << endl;
            end = true;
            break;
        }

    } while (end != true);
    return 0;
}
