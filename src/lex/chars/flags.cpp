#include "all.h"

const unsigned char Char::FLAGS[128] = {
  /*   0 NUL */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   1 SOH */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   2 STX */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   3 ETX */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   4 EOT */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   5 ENQ */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   6 ACK */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   7 BEL */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   8  BS */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*   9  HT */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  10  LF */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  11  VT */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  12  FF */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  13  CR */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  14  SO */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  15  SI */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  16 DLE */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  17 DC1 */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  18 DC2 */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  19 DC3 */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  20 DC4 */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  21 NAK */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  22 SYN */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  23 ETB */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  24 CAN */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  25  EM */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  26 SUB */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  27 ESC */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  28  FS */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  29  GS */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  30  RS */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  31  US */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  32     */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  33   ! */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  34   " */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  35   # */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  36   $ */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  37   % */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  38   & */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  39   ' */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  40   ( */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  41   ) */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  42   * */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  43   + */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  44   , */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  45   - */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  46   . */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  47   / */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  48   0 */ BIN | OCT | DEC | HEX | CONST | LOCAL | CLASS,
  /*  49   1 */ BIN | OCT | DEC | HEX | CONST | LOCAL | CLASS,
  /*  50   2 */ 0   | OCT | DEC | HEX | CONST | LOCAL | CLASS,
  /*  51   3 */ 0   | OCT | DEC | HEX | CONST | LOCAL | CLASS,
  /*  52   4 */ 0   | OCT | DEC | HEX | CONST | LOCAL | CLASS,
  /*  53   5 */ 0   | OCT | DEC | HEX | CONST | LOCAL | CLASS,
  /*  54   6 */ 0   | OCT | DEC | HEX | CONST | LOCAL | CLASS,
  /*  55   7 */ 0   | OCT | DEC | HEX | CONST | LOCAL | CLASS,
  /*  56   8 */ 0   | 0   | DEC | HEX | CONST | LOCAL | CLASS,
  /*  57   9 */ 0   | 0   | DEC | HEX | CONST | LOCAL | CLASS,
  /*  58   : */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  59   ; */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  60   < */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  61   = */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  62   > */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  63   ? */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  64   @ */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  65   A */ 0   | 0   | 0   | HEX | CONST | 0     | CLASS,
  /*  66   B */ 0   | 0   | 0   | HEX | CONST | 0     | CLASS,
  /*  67   C */ 0   | 0   | 0   | HEX | CONST | 0     | CLASS,
  /*  68   D */ 0   | 0   | 0   | HEX | CONST | 0     | CLASS,
  /*  69   E */ 0   | 0   | 0   | HEX | CONST | 0     | CLASS,
  /*  70   F */ 0   | 0   | 0   | HEX | CONST | 0     | CLASS,
  /*  71   G */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  72   H */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  73   I */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  74   J */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  75   K */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  76   L */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  77   M */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  78   N */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  79   O */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  80   P */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  81   Q */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  82   R */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  83   S */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  84   T */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  85   U */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  86   V */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  87   W */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  88   X */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  89   Y */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  90   Z */ 0   | 0   | 0   | 0   | CONST | 0     | CLASS,
  /*  91   [ */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  92   \ */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  93   ] */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  94   ^ */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  95   _ */ 0   | 0   | 0   | 0   | CONST | LOCAL | 0,
  /*  96   ` */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /*  97   a */ 0   | 0   | 0   | HEX | 0     | LOCAL | CLASS,
  /*  98   b */ 0   | 0   | 0   | HEX | 0     | LOCAL | CLASS,
  /*  99   c */ 0   | 0   | 0   | HEX | 0     | LOCAL | CLASS,
  /* 100   d */ 0   | 0   | 0   | HEX | 0     | LOCAL | CLASS,
  /* 101   e */ 0   | 0   | 0   | HEX | 0     | LOCAL | CLASS,
  /* 102   f */ 0   | 0   | 0   | HEX | 0     | LOCAL | CLASS,
  /* 103   g */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 104   h */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 105   i */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 106   j */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 107   k */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 108   l */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 109   m */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 110   n */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 111   o */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 112   p */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 113   q */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 114   r */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 115   s */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 116   t */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 117   u */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 118   v */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 119   w */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 120   x */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 121   y */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 122   z */ 0   | 0   | 0   | 0   | 0     | LOCAL | CLASS,
  /* 123   { */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /* 124   | */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /* 125   } */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /* 126   ~ */ 0   | 0   | 0   | 0   | 0     | 0     | 0,
  /* 127 DEL */ 0   | 0   | 0   | 0   | 0     | 0     | 0
};
