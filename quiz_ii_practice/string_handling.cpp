#include <iostream>
#include <string>
#include <sstream>  // For string buffer (stringstream)
#include <cstring>  // For C-string functions
#include <algorithm> // For transform (toupper, tolower)

void demonstrateStringFunctions() {
    std::cout << "==== STRING CLASS USAGE ====" << std::endl;
    
    // 1. STRING INITIALIZATION & ASSIGNMENT
    std::string str1 = "Hello";
    std::string str2("World");
    std::string str3 = str1 + " " + str2; // Concatenation
    std::cout << "Concatenation: " << str3 << std::endl;

    // 2. STRING COMPARISON
    if (str1 == "Hello") {
        std::cout << "String comparison (==): str1 is Hello" << std::endl;
    }
    std::cout << "Comparison (compare): " << str1.compare(str2) << std::endl;

    // 3. STRING SEARCHING
    std::string sentence = "This is a simple string example";
    size_t found = sentence.find("simple");
    if (found != std::string::npos) {
        std::cout << "'simple' found at index: " << found << std::endl;
    }

    // 4. STRING MODIFICATION
    sentence.insert(5, "INSERTED ");
    std::cout << "After insert: " << sentence << std::endl;

    sentence.replace(5, 9, "REPLACED");
    std::cout << "After replace: " << sentence << std::endl;

    sentence.erase(5, 9);
    std::cout << "After erase: " << sentence << std::endl;

    // 5. STRING SIZE HANDLING
    std::cout << "String length: " << sentence.length() << std::endl;
    std::cout << "String empty?: " << (sentence.empty() ? "Yes" : "No") << std::endl;

    // 6. CHARACTER ACCESS
    std::cout << "Character at index 2: " << sentence.at(2) << std::endl;
    std::cout << "Using operator[]: " << sentence[2] << std::endl;

    // 7. CONVERTING std::string TO C-STYLE STRING
    const char* cstr = sentence.c_str();
    std::cout << "C-style string: " << cstr << std::endl;

    // 8. CONVERTING C-STYLE STRING TO std::string
    char charArr[] = "C-String to std::string";
    std::string fromCStr = std::string(charArr);
    std::cout << "Converted from C-string: " << fromCStr << std::endl;

    // 9. USING STRINGSTREAM AS STRING BUFFER
    std::stringstream ss;
    ss << "Buffered ";
    ss << "String ";
    ss << 2024;
    std::string bufferedString = ss.str();
    std::cout << "String from stringstream: " << bufferedString << std::endl;

    // 10. TOKENIZING A STRING USING STRINGSTREAM
    std::string csv = "Apple,Banana,Cherry,Date";
    std::stringstream ssToken(csv);
    std::string token;
    std::cout << "Tokenized words: ";
    while (getline(ssToken, token, ',')) {
        std::cout << token << " ";
    }
    std::cout << std::endl;

    // 11. STRING TRANSFORMATIONS (UPPERCASE & LOWERCASE)
    std::string text = "Change Me!";
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    std::cout << "Uppercase: " << text << std::endl;
    
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    std::cout << "Lowercase: " << text << std::endl;
}

int main() {
    demonstrateStringFunctions();
    return 0;
}
