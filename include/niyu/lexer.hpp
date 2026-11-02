
#pragma once

#include <string>
#include <vector>

namespace niyu {

enum class TokenType {
    // Literals and identifiers
    Identifier,
    Integer,
    Float,
    String,

    // Keywords
    IntKeyword, 
    BoolKeyword,
    VoidKeyword,
    FloatKeyword,
    StringKeyword,
    ConstKeyword,

    IfKeyword, ElseKeyword,
    ForKeyword, WhileKeyword,
    ReturnKeyword,
    
    TrueKeyword, FalseKeyword,

    // Operators
    Plus, Minus,
    Star, Slash,
    Percent,

    Equal, PlusEqual, MinusEqual,
    StarEqual, SlashEqual,

    EqualEqual, Less, Greater,
    LessEqual, GreaterEqual,

    AndAnd, OrOr, Bang,
    PlusPlus, MinusMinus,

    // Braces and punctuation
    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace,
    Semicolon,
    Comma,

    // Special
    EndOfFile
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

class Lexer {
public:
    explicit Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    std::string source;
    std::vector<Token> tokens;

    size_t pos = 0;
    int line = 1;
    int column = 1;
};

}
