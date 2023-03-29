#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdarg>

class Token {
  public:
    std::string type;
    std::string str;  
};

bool isNumber(char c) {
  return c >= '0' && c <= '9';
}

bool isUpperCase(char c) {
  return c >= 'A' && c <= 'Z';
}

bool isLowerCase(char c) {
  return c >= 'a' && c <= 'z';
}

bool isSpace(char c) {
  return c == ' ';
}

std::vector<Token> tokenise(const std::string& str) {
  std::vector<Token> tokens;

  for (int i = 0; i < str.length(); i++) {
    Token new_token;
    if (isNumber(str[i])) {
      new_token.type = "number";
      for (; isNumber(str[i]); i++) {
        new_token.str += str[i];
      }
      i--;
    } else if (isUpperCase(str[i]) || isLowerCase(str[i])) {
      new_token.type = "string";
      for (; isUpperCase(str[i]) || isLowerCase(str[i]); i++) {
        new_token.str += str[i];
      }
      i--;
    } else if (isSpace(str[i])) {
      new_token.type = "space";
      new_token.str = str[i];
    } else {
      new_token.type = "unknown";
      new_token.str = str[i];
    }
    tokens.push_back(new_token);
  }

  return tokens;
}

std::vector<Token> removeSpace(std::vector<Token>& tokens) {

  for (int i = 0; i < tokens.size(); i++) {
    if (tokens[i].type == "space") {
      tokens.erase(tokens.begin() + i);
      i--;
    }
  }

  return tokens;
}

std::vector<Token> removeTheOthers(std::vector<Token>& tokens) {
  for (int i = 0; i < tokens.size(); i++) {
    if (tokens[i].type != "number" || tokens[i].type != "string") {
      tokens.erase(tokens.begin() + i);
      i--;
    }
  }
  return tokens;
}

int main() {
  std::string str;

  while (std::getline(std::cin, str)) {
    if (str == "exit") {
      std::exit(0);
    } else {
      std::vector<Token> new_tokens = tokenise(str);
      
      for (int i = 0; i < new_tokens.size(); i++) {
        std::cout << new_tokens[i].type << " : " << new_tokens[i].str << std::endl;
      }
      std::cout << std::endl;

      std::vector<Token> new_new_tokens = removeTheOthers(new_tokens);

      for (int i = 0; i < new_new_tokens.size(); i++) {
        std::cout << new_new_tokens[i].str << std::endl;
      }

      new_tokens.clear();
    }
  }

  return 0;
}