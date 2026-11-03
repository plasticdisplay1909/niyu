#include "niyu/lexer.hpp"
#include <unordered_map>
#include <stdexcept>

namespace niyu {

    // Build once at startup
    namespace {
        const std::unordered_map<std::string, TokenType> keywords = {
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
    }

    Lexer::Lexer(const std::string& source)
        : source(source) {}

    bool Lexer::isAtEnd() const{
        return pos>=source.size();
    }

    char Lexer::peek() const {
        if (isAtEnd()) return '\0';         // Null charecter
        return source[pos];
    }

    char Lexer::peekNext() const{
        if (pos+1 >= source.size()) return '\0';
        return source[pos+1];
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

    bool Lexer::isAlpha(char c) const {
        return (
            (c>='a' && c<='z') ||
            (c>='A' && c<='Z') ||
            c=='_'
        );
    }

    bool Lexer::isDigit(char c) const {
        return c>='0' && c<='9';
    }

    bool Lexer::isAlphaNumeric(char c) const{
        return isAlpha(c) || isDigit(c);
    }

    void Lexer::scanIdentifier() {
        startLine=line;
        startColumn=column;

        size_t start = pos;

        while (!isAtEnd() && isAlphaNumeric(peek())) {
            advance();
        }

        std::string word = source.substr(start, pos - start);

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
            if (pos+1 <source.size() && isDigit(peekNext())) {
                isFloat=true;
                advance();          // Consume '.'

                while (!isAtEnd() and isDigit(peek())) {
                    advance();
                }
            } 
        }

        std::string num=source.substr(start,pos-start);
        addToken(isFloat ? TokenType::Float : TokenType::Integer , num);
    }

    void Lexer::scanString() {
        startLine=line;
        startColumn=column;

        // Consume opening quotes
        advance();

        size_t start=pos;
        while (!isAtEnd() and peek()!='"') {
            if (peek()=='\n') {
                throw std::runtime_error(std::to_string(startLine) + ':' + std::to_string(startColumn)+" -> Unterminated String (NewLine before closing quote)");
            }

            advance();
        }

        // End is not by closing quotes
        if (isAtEnd()) {
            throw std::runtime_error(std::to_string(startLine) + ':' + std::to_string(startColumn)+" -> Unterminated String (Reached end of the file)");
        }

        std::string value=source.substr(start,pos-start);

        // Consume closing quotes
        advance();
        addToken(TokenType::String,value);
    }
}


