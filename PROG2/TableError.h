/**
* @file TableError.h
* @author Антонов И.С.
* @version 1.0
* @brief Описание класса TableError
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <stdexcept>
using namespace std;
/// @brief  Класс для обработки ошибок, которые могут возникнуть при взаимодействии пользователя с программой
/// @details Класс является наследником существующего класса обработки исключений с именем invalid_argument
class TableError : public invalid_argument
{
public:
     /// @brief Запрещающий конструктор без параметров
    TableError () = delete;
    /** @brief  Конструктор с параметром
     * @param std::string  what_arg - строка, хранящая описание ошибки. Данный параметр перегружается конструктором класса invalid_argument
     */
    explicit TableError (const string & what_arg) : invalid_argument(what_arg) {};
    /**@brief Статический метод, проверяющий ключ при шифровании или расшифровании на наличие ошибок
     * @param std::string key - ключ, который нужно проверить при шифровании или расшифровании
     * @throw  TableError, если ключ оказался пустым или в ключе присутствуют недопустимые символы
      */
    static void check_key (string key);
    /**@brief Статический метод, проверяющий строку при шифровании или расшифровании на наличие ошибки
     * @param std::string str - строка, которую нужно проверить при шифровании или расшифровании
     * @throw  TableError, если строка оказалось пустой
     * */
    static void check_str (string str);
};
