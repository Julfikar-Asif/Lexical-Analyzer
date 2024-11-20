# Lexical Analyzer in C

This program implements a simple lexical analyzer in C that processes an input string, identifies tokens, and categorizes them into various types such as keywords, variables, operators, numbers, punctuation, and invalid tokens. It is useful for basic token analysis in programming language compilers.

## Features

- **Keyword Detection**: Recognizes C keywords like `int`, `char`, `if`, `else`, etc.
- **Variable Validation**: Identifies valid variable names based on C naming conventions.
- **Operator Detection**: Detects arithmetic and assignment operators (`+`, `-`, `*`, `/`, `=`, `%`).
- **Number Validation**: Validates integers and floating-point numbers.
- **Punctuation Recognition**: Identifies symbols like `;`, `,`, `{`, `}`, etc.
- **Error Detection**: Reports invalid tokens.

---

## How It Works

1. The program reads an input expression from the user.
2. It processes the input character by character, breaking it into tokens.
3. Each token is analyzed and categorized as:
   - **Keyword**
   - **Number**
   - **Variable**
   - **Operator**
   - **Punctuation**
   - **Invalid Token**

---

## Code Structure

### 1. **Functions**
- **`isKeyword(char* str)`**: Checks if the token is a C keyword.
- **`checkVariable(char* var)`**: Validates whether the token is a valid variable name.
- **`isOperator(char c)`**: Checks if the character is a valid operator.
- **`isNumber(char* str)`**: Validates integers and floating-point numbers.
- **`isPunctuation(char c)`**: Identifies punctuation characters.
- **`lex(char* input)`**: The core function that processes the input and classifies tokens. 

### 2. **Main Function**
- Reads input from the user.
- Calls the `lex` function to analyze the input.

## Run the program 
- **`./lexical_analyzer`**

