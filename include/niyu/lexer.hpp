#pragma once

#include <string>
#include <vector>

namespace niyu {
    // Literals and identifiers
    Identifer,
    Integer,
    Float,
    string


    // Keywords
    Int,
    Bool,
    Void,
    FloatType,
    Const,

    If, Else,
    For, While,
    Return,
    
    True, False,

    // Operators
    Plus,
    Minus,
    Star,
    Percent,
    Equal, PlusEqual,MinusEqual,StarEqual,SlashEqual,
    Less,Greater,LessEqual,GreaterEqual,
    PlusPlus,MinusMinus

    // Braces
    LeftParen,RightParen,
    LeftBrace,RightBrace,
    Semicolon,Comma

    EndofFile
}

struct Token {
    TokenType type;
    std::string value;
    int line,column;
}

class Lexar {
    public:
        explicit Lexar(const std::string& source);
        std::vector<Token> tokenize();
    private:
        std::string source;
        std::vector<Token> tokens;

        size_t pos = 0;
        int line = 1;
        int column = 1;
};
