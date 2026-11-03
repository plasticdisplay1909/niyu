#include "niyu/lexer.hpp"
#include <unordered_map>

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

    bool Lexer::match(char expected) {
        if (isAtEnd()) return false;
        char current=peek();

        if (current != expected) return false;
        
        advance();
        return true;
    }

    void Lexer::addToken(TokenType type, const std::string& value) {
        tokens.push_back({type,value,startLine,startColumn});
    }

    bool Lexer::isAlpha(char c) {
        return (
            (c>='a' && c<='z') ||
            (c>='A' && c<='Z') ||
            c=='_'
        );
    }

    bool Lexer::isDigit(char c) {
        return (c>='0' && c<='9');
    }

    bool Lexer::isAlphaNumeric(char c) {
        return isAlpha(c) || isDigit(c);
    }

    void Lexer::scanIdentifier() {
        size_t start = pos;

        while (!isAtEnd() && isAlphaNumeric(peek())) {
            advance();
        }

        std::string word = source.substr(start, pos - start);

        static const std::unordered_map<std::string, TokenType> keywords = {
            {"int", TokenType::IntKeyword},
            {"float", TokenType::FloatKeyword},
            {"bool", TokenType::BoolKeyword},
            {"string", TokenType::StringKeyword},
            {"void", TokenType::VoidKeyword},
            {"const", TokenType::ConstKeyword},
            {"if", TokenType::IfKeyword},
            {"else", TokenType::ElseKeyword},
            {"for", TokenType::ForKeyword},
            {"while", TokenType::WhileKeyword},
            {"return", TokenType::ReturnKeyword},
            {"true", TokenType::TrueKeyword},
            {"false", TokenType::FalseKeyword}
        };

        auto it = keywords.find(word);

        if (it != keywords.end()) {
            addToken(it->second, word);
        } else {
            addToken(TokenType::Identifier, word);
        }
    }

    void Lexer::scanNumber() {
        size_t start=pos;
        bool isFloat=false;

        startLine=line;
        startColumn=column;

        while (!isAtEnd() && isDigit(peek())) {
            advance();
        }

        if (!isAtEnd() && peek()=='.') {
            if (pos+1 <source.size() && isDigit[source[pos+1]]) {
                isFloat=true;
                advance();

                while (!isAtEnd() and isDigit(peek())) {
                    advance();
                }
            } 
        }

        std::string num=source.substr(start,pos-start);
        addToken(isFloat ? TokenType::Float : TokenType::Integer , num)
    }
}


