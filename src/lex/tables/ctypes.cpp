#include "../lexlets/all.h"

const char Lexer::CTYPES[128] = {
  /*   0 NUL */ Lexer::INVALID,
  /*   1 SOH */ Lexer::INVALID,
  /*   2 STX */ Lexer::INVALID,
  /*   3 ETX */ Lexer::INVALID,
  /*   4 EOT */ Lexer::INVALID,
  /*   5 ENQ */ Lexer::INVALID,
  /*   6 ACK */ Lexer::INVALID,
  /*   7 BEL */ Lexer::INVALID,
  /*   8  BS */ Lexer::INVALID,
  /*   9  HT */ Lexer::INVALID,
  /*  10  LF */ Lexer::NEWLINE,
  /*  11  VT */ Lexer::INVALID,
  /*  12  FF */ Lexer::INVALID,
  /*  13  CR */ Lexer::INVALID,
  /*  14  SO */ Lexer::INVALID,
  /*  15  SI */ Lexer::INVALID,
  /*  16 DLE */ Lexer::INVALID,
  /*  17 DC1 */ Lexer::INVALID,
  /*  18 DC2 */ Lexer::INVALID,
  /*  19 DC3 */ Lexer::INVALID,
  /*  20 DC4 */ Lexer::INVALID,
  /*  21 NAK */ Lexer::INVALID,
  /*  22 SYN */ Lexer::INVALID,
  /*  23 ETB */ Lexer::INVALID,
  /*  24 CAN */ Lexer::INVALID,
  /*  25  EM */ Lexer::INVALID,
  /*  26 SUB */ Lexer::INVALID,
  /*  27 ESC */ Lexer::INVALID,
  /*  28  FS */ Lexer::INVALID,
  /*  29  GS */ Lexer::INVALID,
  /*  30  RS */ Lexer::INVALID,
  /*  31  US */ Lexer::INVALID,
  /*  32     */ Lexer::SPACE,
  /*  33   ! */ Lexer::OPERATOR,
  /*  34   " */ Lexer::QUOTE,
  /*  35   # */ Lexer::COMMENT,
  /*  36   $ */ Lexer::OPERATOR,
  /*  37   % */ Lexer::OPERATOR,
  /*  38   & */ Lexer::OPERATOR,
  /*  39   ' */ Lexer::QUOTE,
  /*  40   ( */ Lexer::BRACKET,
  /*  41   ) */ Lexer::BRACKET,
  /*  42   * */ Lexer::OPERATOR,
  /*  43   + */ Lexer::OPERATOR,
  /*  44   , */ Lexer::OPERATOR,
  /*  45   - */ Lexer::OPERATOR,
  /*  46   . */ Lexer::OPERATOR,
  /*  47   / */ Lexer::OPERATOR,
  /*  48   0 */ Lexer::IDENTIFIER,
  /*  49   1 */ Lexer::IDENTIFIER,
  /*  50   2 */ Lexer::IDENTIFIER,
  /*  51   3 */ Lexer::IDENTIFIER,
  /*  52   4 */ Lexer::IDENTIFIER,
  /*  53   5 */ Lexer::IDENTIFIER,
  /*  54   6 */ Lexer::IDENTIFIER,
  /*  55   7 */ Lexer::IDENTIFIER,
  /*  56   8 */ Lexer::IDENTIFIER,
  /*  57   9 */ Lexer::IDENTIFIER,
  /*  58   : */ Lexer::OPERATOR,
  /*  59   ; */ Lexer::OPERATOR,
  /*  60   < */ Lexer::OPERATOR,
  /*  61   = */ Lexer::OPERATOR,
  /*  62   > */ Lexer::OPERATOR,
  /*  63   ? */ Lexer::OPERATOR,
  /*  64   @ */ Lexer::OPERATOR,
  /*  65   A */ Lexer::IDENTIFIER,
  /*  66   B */ Lexer::IDENTIFIER,
  /*  67   C */ Lexer::IDENTIFIER,
  /*  68   D */ Lexer::IDENTIFIER,
  /*  69   E */ Lexer::IDENTIFIER,
  /*  70   F */ Lexer::IDENTIFIER,
  /*  71   G */ Lexer::IDENTIFIER,
  /*  72   H */ Lexer::IDENTIFIER,
  /*  73   I */ Lexer::IDENTIFIER,
  /*  74   J */ Lexer::IDENTIFIER,
  /*  75   K */ Lexer::IDENTIFIER,
  /*  76   L */ Lexer::IDENTIFIER,
  /*  77   M */ Lexer::IDENTIFIER,
  /*  78   N */ Lexer::IDENTIFIER,
  /*  79   O */ Lexer::IDENTIFIER,
  /*  80   P */ Lexer::IDENTIFIER,
  /*  81   Q */ Lexer::IDENTIFIER,
  /*  82   R */ Lexer::IDENTIFIER,
  /*  83   S */ Lexer::IDENTIFIER,
  /*  84   T */ Lexer::IDENTIFIER,
  /*  85   U */ Lexer::IDENTIFIER,
  /*  86   V */ Lexer::IDENTIFIER,
  /*  87   W */ Lexer::IDENTIFIER,
  /*  88   X */ Lexer::IDENTIFIER,
  /*  89   Y */ Lexer::IDENTIFIER,
  /*  90   Z */ Lexer::IDENTIFIER,
  /*  91   [ */ Lexer::BRACKET,
  /*  92   \ */ Lexer::OPERATOR,
  /*  93   ] */ Lexer::BRACKET,
  /*  94   ^ */ Lexer::OPERATOR,
  /*  95   _ */ Lexer::IDENTIFIER,
  /*  96   ` */ Lexer::QUOTE,
  /*  97   a */ Lexer::IDENTIFIER,
  /*  98   b */ Lexer::IDENTIFIER,
  /*  99   c */ Lexer::IDENTIFIER,
  /* 100   d */ Lexer::IDENTIFIER,
  /* 101   e */ Lexer::IDENTIFIER,
  /* 102   f */ Lexer::IDENTIFIER,
  /* 103   g */ Lexer::IDENTIFIER,
  /* 104   h */ Lexer::IDENTIFIER,
  /* 105   i */ Lexer::IDENTIFIER,
  /* 106   j */ Lexer::IDENTIFIER,
  /* 107   k */ Lexer::IDENTIFIER,
  /* 108   l */ Lexer::IDENTIFIER,
  /* 109   m */ Lexer::IDENTIFIER,
  /* 110   n */ Lexer::IDENTIFIER,
  /* 111   o */ Lexer::IDENTIFIER,
  /* 112   p */ Lexer::IDENTIFIER,
  /* 113   q */ Lexer::IDENTIFIER,
  /* 114   r */ Lexer::IDENTIFIER,
  /* 115   s */ Lexer::IDENTIFIER,
  /* 116   t */ Lexer::IDENTIFIER,
  /* 117   u */ Lexer::IDENTIFIER,
  /* 118   v */ Lexer::IDENTIFIER,
  /* 119   w */ Lexer::IDENTIFIER,
  /* 120   x */ Lexer::IDENTIFIER,
  /* 121   y */ Lexer::IDENTIFIER,
  /* 122   z */ Lexer::IDENTIFIER,
  /* 123   { */ Lexer::BRACKET,
  /* 124   | */ Lexer::OPERATOR,
  /* 125   } */ Lexer::BRACKET,
  /* 126   ~ */ Lexer::OPERATOR,
  /* 127 DEL */ Lexer::INVALID
};
