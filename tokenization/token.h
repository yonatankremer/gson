typedef enum token
{
    COMMENT, //(#)
    LINEBREAK, // (\n)
    SPACE, // ( )

    STR_QUOT, // (")

    COLON, // (:)

    OBJ_START, // ({)
    OBJ_END, // (})

    END_OF_FILE, // (;)

    IDENTIFIER, //variable name
    STR_CONTENT // ("some things")

} token;
