#include <UnitTest++/UnitTest++.h>
#include "/home/student/2laba/1zadanie/modAlphaCipher.h"
#include "/home/student/2laba/1zadanie/modAlphaCipher.cpp"

SUITE(KeyTest) // для ключа
{
    TEST(SmallRussian) {
        modAlphaCipher test(L"маленькие");
        CHECK(true);
    }
    TEST(BigRussian) {
        modAlphaCipher test(L"БОЛЬШИЕ");
        CHECK(true);
    }
    TEST(BigAndSmallRussian) {
        modAlphaCipher test(L"ВВВВааааа");
        CHECK(true);
    }
    TEST(EmptyKey) {
        CHECK_THROW(modAlphaCipher test(L""), CipherError);
    }
    TEST(KeyWithSpace) {
        CHECK_THROW(modAlphaCipher test(L"ало ало"), CipherError);
    }
    TEST(InvalidCharactersNumber) {
        CHECK_THROW(modAlphaCipher test(L"123пр"),CipherError);
    }
    TEST(InvalidCharactersSpecial) {
        CHECK_THROW(modAlphaCipher test(L";,РРР"), CipherError);
    }
}

struct Key_fixture { 
    modAlphaCipher * p;
    Key_fixture()
    {
        p = new modAlphaCipher(L"АБВ");
    }
    ~Key_fixture()
    {
        delete p;
    }
};

SUITE(EncryptTest) // Шифрование
{
    TEST_FIXTURE(Key_fixture, BigRussian) {
        wstring text = L"ПРИВЕТМИР";
        wstring result = L"ПСКВЁФМЙТ";
        CHECK_EQUAL(true, result == p->encrypt(text));
    }
    TEST_FIXTURE(Key_fixture, SmallRussian) {
        wstring text = L"приветмир";
        wstring result = L"ПСКВЁФМЙТ";
        CHECK_EQUAL(true, result == p->encrypt(text));
    }
    TEST_FIXTURE(Key_fixture, BigAndSmallRussian) {
        wstring text = L"БОЛмал";
        wstring result = L"БПНМБН";
        CHECK_EQUAL(true, result == p->encrypt(text));
    }

    TEST_FIXTURE(Key_fixture, EmptyText) {
        wstring text = L"";
        CHECK_THROW(p->encrypt(text),CipherError);
    }
    TEST_FIXTURE(Key_fixture,InvalidCharactersNumbers ) {
        wstring text = L"ПРИВ12";
        CHECK_THROW(p->encrypt(text),CipherError);
    }
    TEST_FIXTURE(Key_fixture,InvalidCharactersSpecial) {
        wstring text = L":ПР,";
        CHECK_THROW(p->encrypt(text),CipherError);
    }
    TEST_FIXTURE(Key_fixture,TextWithSpace ) {
        wstring text = L"ПРО БЕЛ";
        CHECK_THROW(p->encrypt(text), CipherError);
    }

}

SUITE(DecryptTest) // расшифрование
{
   TEST_FIXTURE(Key_fixture, BigRussian) {
        wstring cipher_text = L"ПСКВЁФМЙТ";
        wstring result = L"ПРИВЕТМИР";
        CHECK_EQUAL(true, result == p->decrypt(cipher_text));
    }
    TEST_FIXTURE(Key_fixture, SmallRussian) {
        wstring cipher_text = L"псквёфмйт";
        wstring result = L"ПРИВЕТМИР";
        CHECK_EQUAL(true, result == p->decrypt(cipher_text));
    }
    TEST_FIXTURE(Key_fixture, BigAndSmallRussian) {
        wstring cipher_text = L"БПНмбн";
        wstring result = L"БОЛМАЛ";
        CHECK_EQUAL(true, result == p->decrypt(cipher_text));
    }

    TEST_FIXTURE(Key_fixture, EmptyText) {
        wstring cipher_text = L"";
        CHECK_THROW(p->decrypt(cipher_text),CipherError);
    }
    TEST_FIXTURE(Key_fixture,InvalidCharactersNumbers ) {
        wstring cipher_text = L"АА123";
        CHECK_THROW(p->decrypt(cipher_text),CipherError);
    }
    TEST_FIXTURE(Key_fixture,InvalidCharactersSpecial ) {
        wstring cipher_text = L"(АА*";
        CHECK_THROW(p->decrypt(cipher_text),CipherError);
    }
    TEST_FIXTURE(Key_fixture,TextWithSpace ) {
        wstring cipher_text = L"ПРО БЕЛ";
        CHECK_THROW(p->decrypt(cipher_text),CipherError);
    }

}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
