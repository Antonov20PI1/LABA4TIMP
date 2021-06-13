/**
* @file CipherError.h
* @author Антонов И.С.
* @version 1.0
* @brief Описание класса CipherError
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <stdexcept>
using namespace std;
/// @brief  Класс для обработки ошибок, которые могут возникнуть при взаимодействии пользователя с программой
/// @details Класс является наследником существующего класса обработки исключений с именем invalid_argument
class CipherError: public invalid_argument
{
public:
    /// @brief Запрещающий конструктор без параметров
    CipherError () = delete;
    /** @brief  Конструктор с параметром
     * @param std::string  what_arg - строка, хранящая описание ошибки. Данный параметр перегружается конструктором класса invalid_argument
     */
    explicit CipherError (const string & what_arg) : invalid_argument(what_arg) {};
};
