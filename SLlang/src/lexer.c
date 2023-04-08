#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


lexer_T* init_lexer(char* contents)
{
    lexer_T* lexer = malloc(sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = *contents;

    return lexer;
}

void lexer_advance(lexer_T* lexer)
{
    if (lexer->c && lexer->i < strlen(lexer->contents))
    {
        lexer->c = lexer->contents[++lexer->i];
    }
}

void lexer_skip_whitespace(lexer_T* lexer)
{
    while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
    {
        lexer_advance(lexer);
    }
}

token_T* lexer_get_next_token(lexer_T* lexer)
{
    while (lexer->c && lexer->i < strlen(lexer->contents))
    {
        lexer_skip_whitespace(lexer);

        if (isalnum(lexer->c))
            return lexer_collect_id(lexer);

        if (lexer->c == '"')
            return lexer_collect_string(lexer);

        switch (lexer->c)
        {
            case '=': return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer))); break;
            case ';': return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_string(lexer))); break;
            case '(': return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_string(lexer))); break;
            case ')': return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_string(lexer))); break;
            case '{': return lexer_advance_with_token(lexer, init_token(TOKEN_LBRACE, lexer_get_current_char_as_string(lexer))); break;
            case '}': return lexer_advance_with_token(lexer, init_token(TOKEN_RBRACE, lexer_get_current_char_as_string(lexer))); break;
            case ',': return lexer_advance_with_token(lexer, init_token(TOKEN_COMMA, lexer_get_current_char_as_string(lexer))); break;
        }
    }

    return init_token(TOKEN_EOF, 0);
}

token_T* lexer_collect_string(lexer_T* lexer)
{
    lexer_advance(lexer);

    
    char* quotationMark = strchr(lexer->c, '"');
    if (quotationMark == NULL) {
        return NULL;
    }
    size_t len = quotationMark - lexer->c;
    char* value = strndup(lexer->c, len);
    
    for (size_t i = 0; i < len; i++){
        lexer_advance(lexer);
    }
    lexer_advance(lexer);

    return init_token(TOKEN_STRING, value);
}

token_T* lexer_collect_id(lexer_T* lexer)
{
    char* value = malloc(1);
    value[0] = 0;

    while (isalnum(lexer->c))
    {
        size_t len = strlen(value);
        value = realloc(value, len+2);
        value[len] = lexer->c;
        value[len+1] = 0;

        lexer_advance(lexer);
    }

    return init_token(TOKEN_ID, value);
}

token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token)
{
    lexer_advance(lexer);

    return token;
}

char* lexer_get_current_char_as_string(lexer_T* lexer)
{
    char* str = malloc(2);
    str[0] = lexer->c;
    str[1] = 0;

    return str;
}



