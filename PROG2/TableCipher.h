/**
* @file TableCipher.h
* @author Антонов И.С.
* @version 1.0
* @brief Описание класса TableCipher
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
using namespace std;
/// @brief Класс для шифрования и расшифрования шифра табличной маршрутной перестановки
class TableCipher
{
private:
    /// @brief атрибут, хранящий ключ для шифрования или расшифрования. Количество столбцов таблицы
    int key;
public:
    /// @brief Запрещающий конструктор без параметров
    TableCipher() = delete;
    /** @brief Конструктор для ключа
    *   @param целочисленное число - ключ
    *   @details число, которое пришло на вход записывается в атрибут с названием key
    */
    TableCipher(const int key);
    /** @brief Метод , предназначенный для шифрования шифром табличной маршрутной перестановки
     *@param объект класса TableCipher, в котором установился ключ
     *@param std::wstring str - строка, которую нужно зашифровать
     * @return зашифрованная строка типа "wstring"
     */
    wstring encryptTableCipher(TableCipher key, wstring & str);
    /** @brief Метод , предназначенный для расшифрования шифра табличной маршрутной перестановки
     *@param объект класса TableCipher, в котором установился ключ
     *@param std::wstring str - строка, которую нужно расшифровать
     * @return расшифрованная строка типа "wstring"
     */
    wstring decryptTableCipher(TableCipher key, wstring & str);
};
