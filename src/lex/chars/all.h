#ifndef CUBIT_LEX_CHARS_H
#define CUBIT_LEX_CHARS_H

class Char {
public:
  // Bases for use in FLAGS:
  static const unsigned char BIN = 0x01;
  static const unsigned char OCT = 0x02;
  static const unsigned char DEC = 0x04;
  static const unsigned char HEX = 0x08;

  // Name styles for use in FLAGS:
  static const unsigned char CONST = 0x10;
  static const unsigned char LOCAL = 0x20;
  static const unsigned char CLASS = 0x30;

  // Lexlet types for use in TYPES:
  static const unsigned char BRACKET    = 0;
  static const unsigned char COMMENT    = 1;
  static const unsigned char SPACE      = 2;
  static const unsigned char IDENTIFIER = 3;
  static const unsigned char NEWLINE    = 4;
  static const unsigned char OPERATOR   = 5;
  static const unsigned char QUOTE      = 6;
  static const unsigned char NUMBER     = 7;
  static const unsigned char INVALID    = 8;

  // The actual tables:
  static const unsigned char FLAGS[128];
  static const          char NAMES[128][4];
  static const unsigned char TYPES[128];

public:
  static const unsigned char flags(int c) {
    if(c < 0 || c > 127) return 0;
    return FLAGS[c];
  }

  static const char* name(int c) {
    if(c < 0 || c > 127) return "???";
    return NAMES[c];
  }

  static const unsigned char type(int c) {
    if(c < 0 || c > 127) return INVALID;
    return TYPES[c];
  }
};

#endif
