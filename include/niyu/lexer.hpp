
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
    BangEqual,

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

    bool isAtEnd() const;
    char advance();
    char peek() const;
    char peekNext() const;
    bool match(char expected);

    int startColumn=1;
    int startLine=1;
    void addToken(TokenType type, const std::string& value);

    bool isAlpha(char c) const;
    bool isDigit(char c) const;
    bool isAlphaNumeric(char c) const;

    void scanIdentifier();
    void scanNumber();
    void scanString();

};

}
