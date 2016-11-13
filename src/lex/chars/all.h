#ifndef CUBIT_LEX_CHARS_H
#define CUBIT_LEX_CHARS_H

class Char {
public:
  // Bases for use in FLAGS:
  static const unsigned char BIN = 0x01;
  static const unsigned char OCT = 0x03;
  static const unsigned char DEC = 0x07;
  static const unsigned char HEX = 0x0f;

  // Naming schemes for use in FLAGS:
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
  static const unsigned char INVALID    = 7;

  // The actual tables:
  static const unsigned char FLAGS[128];
  static const          char NAMES[128][4];
  static const unsigned char TYPES[128];
};

#endif
