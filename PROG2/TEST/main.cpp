#include <UnitTest++/UnitTest++.h>
#include "/home/student/2laba/2zadanie/TableCipher.h"
#include "/home/student/2laba/2zadanie/TableCipher.cpp"
#include "/home/student/2laba/2zadanie/TableError.h"
#include "/home/student/2laba/2zadanie/TableError.cpp"
SUITE(EncryptTest)
{
    const int key = 3;
    TableCipher test(key);
    TEST(BigSmallRussian) {
        wstring text = L"ХЕЛОУмир";
        wstring result = L"ХОиЕУрЛм ";
        CHECK_EQUAL(true, result == test.encryptTableCipher(test,text));
    }
    TEST(SmallEnglish) {
        wstring text = L"bmwmercedesaudi";
        wstring result = L"bmceumeesdwrdai";
        CHECK_EQUAL(true, result == test.encryptTableCipher(test,text));
    }
    TEST(BigSmallEnglish) {
        wstring text = L"CARbmw";
        wstring result = L"CbAmRw";
        CHECK_EQUAL(true, result == test.encryptTableCipher(test,text));
    }
    TEST(SpecialCharacters) {
        wstring text = L"**()&^%_-";
        wstring result = L"*)%*&_(^-";
        CHECK_EQUAL(true, result == test.encryptTableCipher(test,text));
    }
    TEST(Numbers) {
        wstring text = L"0123456789";
        wstring result = L"0369147 258";
        CHECK_EQUAL(true, result == test.encryptTableCipher(test,text));
    }
    TEST(AllCharacters) {
        wstring text = L"БОЛ мал Hell word 0123*()";
        wstring result = L"Б лe r03)Ом lwd1* ЛаHlo 2(";
        CHECK_EQUAL(true, result == test.encryptTableCipher(test,text));
    }

}
SUITE(DecryptTest)
{
    const int key = 3;
    TableCipher test(key);
    TEST(BigSmallRussian) {
        wstring text = L"ХОиЕУрЛм";
        wstring result = L"ХЕЛОУмир";
        CHECK_EQUAL(true, result == test.decryptTableCipher(test,text));
    }
    TEST(SmallEnglish) {
        wstring text = L"bmceumeesdwrdai";
        wstring result = L"bmwmercedesaudi";
        CHECK_EQUAL(true, result == test.decryptTableCipher(test,text));
    }
    
    TEST(BigSmallEnglish) {
        wstring text = L"CbAmRw";
        wstring result = L"CARbmw";
        CHECK_EQUAL(true, result == test.decryptTableCipher(test,text));
    }
    
    TEST(SpecialCharacters) {
        wstring text = L"*)%*&_(^-";
        wstring result = L"**()&^%_-";
        CHECK_EQUAL(true, result == test.decryptTableCipher(test,text));
    }
    TEST(Numbers) {
        wstring text = L"968574";
        wstring result = L"987654";
        CHECK_EQUAL(true, result == test.decryptTableCipher(test,text));
    }
    TEST(AllCharacters) {
        wstring text = L"pВ r(rеM0)iтi1";
        wstring result = L"priВет Mir01()";
       CHECK_EQUAL(true, result == test.decryptTableCipher(test,text));
    }
}

SUITE(StrokaTest)
{
    TEST(BigSmallRussianLetters) {
        TableError::check_str("русскаяСТР");
        CHECK(true);
    }
    TEST(BigSmallEnglishLetters) {
        TableError::check_str("helloWORLD");
        CHECK(true);
    }
    TEST(AllCharacters) {
        TableError::check_str("heLLO Мир 123*()");
        CHECK(true);
    }
    TEST(EmptyStroka) {
        CHECK_THROW(TableError::check_str(""),TableError);
    }
}
SUITE(KeyTest)
{
    TEST(CorrectKey) {
        TableError::check_key("5");
        CHECK(true);
    }
    TEST(NegativeNumber) {
        CHECK_THROW(TableError::check_key("-4"), TableError);
    }
    TEST(StrokaTexta) {
        CHECK_THROW(TableError::check_key("text текст 13(0"), TableError);
    }
    TEST(EmptyKey) {
        CHECK_THROW(TableError::check_key(""),TableError);
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
