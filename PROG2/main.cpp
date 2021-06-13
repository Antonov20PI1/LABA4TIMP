#include <iostream>
#include "TableCipher.h"
#include "TableError.h"
#include <locale>
#include <codecvt>
int main()
{
    bool end = false;
    string rejim, str, sKey;
    cout << "Добро пожаловать в программу, которая реализует шифр табличной маршрутной перестановки." << endl;
    cout << "1 - режим шифрования шифром табличной маршрутной перестановки.\n";
    cout << "2 - режим расшифрования шифра табличной маршрутной перестановки.\n";
    cout << "exit - завершить работу программы." << endl;
    do {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Выберите режим работы: ";
        cin >> rejim;
        if (rejim == "1") {
            cout << "Введите строку для шифрования: ";
            cin.get();
            getline(cin, str);
            try {
                TableError::check_str(str);
                cout << "Введите ключ: ";
                getline(cin,sKey);
                TableError::check_key(sKey);
                int key = stoi(sKey);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                wstring wstr = codec.from_bytes(str);
                TableCipher en(key);
                cout<< "Result: " << codec.to_bytes(en.encryptTableCipher(en,wstr))<<endl;
            } catch (const TableError & error) {
                cout << "Ошибка: " << error.what() << endl;
            }
        }
        if (rejim == "2") {
            cout << "Введите строку для расшифрования: ";
            cin.get();
            getline(cin, str);
            try {
                TableError::check_str(str);
                cout << "Введите ключ: ";
                getline(cin,sKey);
                TableError::check_key(sKey);
                int key = stoi(sKey);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                wstring wstr = codec.from_bytes(str);
                TableCipher dec(key);
                cout<< "Result: " << codec.to_bytes(dec.decryptTableCipher(dec,wstr))<<endl;
            } catch (const TableError & error) {
                cout << "Ошибка: " << error.what() << endl;
            }
        }
        if (rejim == "exit") {
            cout << "До свидания!" << endl;
            end = true;
            break;
        }
    } while (end != true);
    return 0;
}
