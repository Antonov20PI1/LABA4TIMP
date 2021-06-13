#include "TableError.h"
void TableError::check_key(string key)
{
    if (key.empty()) {
        throw TableError("вы ввели пустой ключ.\nКлюч должен быть натуральным числом.");
    }
    
    if (key.find_first_not_of("-0123456789",0) != string::npos) {
        throw TableError("вы ввели недопустимый ключ.\nКлюч должен быть натуральным числом.");
    }
    
    int result = stoi(key);
    if (result <= 0) {
        throw TableError("вы ввели недопустимый ключ.\nКлюч должен быть натуральным числом.");
    }
}
void TableError::check_str(string str)
{
    if (str.empty()) {
        throw TableError("вы ввели пустую строку.");
    }
}
