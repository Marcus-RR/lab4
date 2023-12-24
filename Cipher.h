/**  @file
*   @author Belov I.A.
*  @version 1.0.0
*   @date 24.12.2023
*   @brief Заголовочный файл для модуля Cipher.h
*/

#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
/** @class Cipher
 *  @author Belov I.A.
 *  @version 1.0.0
 * @file Cipher.h
 * @brief Шифрование методом Гронсфельда
 * @detalies Для зашифрования и расшифрования сообщения предназначены методы encrypt и decrypt. Текст на обработку передается в качестве параметра.
 * @warnings Реализация только для русского языка!
 */
class Cipher
{
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
    std::map <char,int> alphaNum; //ассоциативный массив "номер по символу"
    std::vector <int> key; //ключ
    std::vector<int> convert(const std::wstring& s); //преобразование строка-вектор
    std::wstring convert(const std::vector<int>& v); //преобразование вектор-строка
    /** @brief Метод класса, проверяющий ключ на валидность
     * @param [in] s Ключ
     * @return result
     */
    std::wstring getValidKey(const std::wstring & s);
     /** @brief Метод класса, проверяющий текс на валидность
     * @param [in] s Текст на русском языке
     * @return result
     */
    std::wstring getValidOpenText(const std::wstring & s);
    /** @brief Метод класса, проверяющий расшифрованный текст на валидность
     * @param [in] s Зашифрованный текст на русском языке
     * @return result
     */
    std::wstring getValidCipherText(const std::wstring & s);
    
public:
    Cipher()=delete; //запретим конструктор без параметров
     /** @brief Конструктор для создания объекта, хранящего в себе ключ шифрования
     * @param [in] text Открытый текст на русском языке
     * @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     */
    Cipher(const std::wstring& skey);
    /** @brief Зашифрование
     * @param [in] text Открытый текст на русском языке
     * @warnings Текс не должен быть пустоц строкой. В тексте могут содержаться знаки перпинания и цифры.
     * @return result Зашифрованный текст
     */
    std::wstring encrypt(const std::wstring& open_text);//зашифрование
    /** @brief Расшифровывание
     * @param [in] text Расшифрованный текст на русском языке
     * @warnings Текс не должен быть пустоц строкой. В тексте могут содержаться знаки перпинания и цифры.
     * @return result Зашифрованный текст
     */
    std::wstring decrypt(const std::wstring& cipher_text);//расшифрование
};
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
