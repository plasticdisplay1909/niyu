
#include "niyu/lexer.hpp"

namespace niyu {

    Lexer::Lexer(const std::string& source)
        : source(source) {}

    bool Lexer::isAtEnd() {
        return pos>=source.size();
    }

    char Lexer::peek() {
        if (isAtEnd()) return '\0';         // Null charecter
        return source[pos];
    }

    char Lexer::advance() {
        if (isAtEnd()) return '\0';
        char c=source[pos++];

        if (c=='\n') {
            line++;
            column=1;
        } else {
            column++;
        }

        return c;
    }
}


