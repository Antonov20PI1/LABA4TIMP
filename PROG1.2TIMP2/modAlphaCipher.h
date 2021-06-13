/**
* @file modAlphaCipher.h
* @author Антонов И.С.
* @version 1.0
* @brief Описание класса modAlphaCipher
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <vector>
#include <map>
#include <locale>
#include <cctype>
#include "CipherError.h"
using namespace std;
/**  @brief  Класс, предназначенный для шифрования сообщений методом Гронсвельда
* @warning Работает только с русскоязычными сообщениями
* */
class modAlphaCipher
{
private:
    /// @brief  Используемый алфавит для сообщений
    wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    /// @brief  Ассоциативный массив "номер по символу"
    map <char,int> alphaNum;
    /// @brief Атрибут для ключа
    vector <int> key;
    /** @brief  Преобразование строки в вектор(чисел)
     *  @param std::wstring s - строка для преобразования в вектор(чисел)
     *  @return std::vector <int>, в котором хранятся индексы букв сообщения из алфавита numAlpha
     * */
    vector<int> convert(const wstring& s);
    /** @brief Преобразование вектора(чисел) в строку
     *  @param std::vector<int> v - вектор чисел, которые преобразуются в строку по индексам
     *  @return строка текста типа wstring
     * */ 
    wstring convert(const vector<int>& v);
    /**@brief Метод, предназначенный для валидации ключа
    * @param std::wstring s - ключ, который нужно проверить на наличие ошибок
    * @warning Письменные буквы алфавита переводятся в прописные
    * @throw CipherError, если ключ является пустым или в нём присутствуют недопустимые символы
    * @return Ключ типа wstring, который успешно прошёл валидацию
    **/
    wstring getValidKey(const wstring & s);
    /**@brief Метод, предназначенный для валидации строки при шифровании или расшифровании
     * @param std::wstring s - строка, которую нужно проверить на наличие ошибок
     * @warning Письменные буквы алфавита переводятся в прописные
     * @throw CipherError, если строка является пустой или в ней присутствуют недопустимые символы
     * @return строка типа wstring, которая успешно прошла валидацию
    **/
    wstring getValidText(const wstring & s);
public:
    /// @brief Запрещающий конструктор без параметров
    modAlphaCipher()=delete;
     /** @brief  Конструктор для ключа
      * @param std::wstring - ключ в виде строки
      */ 
    modAlphaCipher(const wstring& skey); 
    /** @brief Метод, предназначенный для шифрования
     * @param std::wstring open_text - текст для зашифрования
     * @return Зашифрованаая методом Гронсфельда строка типа wstring
     * */
    wstring encrypt(const wstring& open_text); 
    /**@brief Метод, предназначенный для расшифрования
     * @param std::wstring cipher_text - текст для расшифрования
     * @return Расшифрованаая методом Гронсфельда строка типа wstring
     * */
    wstring decrypt(const wstring& cipher_text);
};
