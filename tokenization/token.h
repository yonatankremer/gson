#ifndef TOKEN_H
#define TOKEN_H
#endif

typedef enum
{
    COMMENT, //(#)
    LINEBREAK, // (\n)
    SPACE, // ( )

    STR_QUOT, // (")

    COLON, // (:)

    OBJ_START, // ({)
    OBJ_END, // (})


    IDENTIFIER, //variable name
    STR_CONTENT // ("some things")

} token;
