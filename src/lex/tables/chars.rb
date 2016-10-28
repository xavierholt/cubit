#! /usr/bin/env ruby

$table = ['Lexer::INVALID'] * 128
$codes = %w(NUL SOH STX ETX EOT ENQ ACK BEL BS HT LF VT FF CR SO SI DLE DC1 DC2 DC3 DC4 NAK SYN ETB CAN EM SUB ESC FS GS RS US)
$flags = [0] * 128

def set(str, type, flags = 0)
  str.chars.each do |c|
    $table[c.ord] = "Lexer::#{type}"
    $flags[c.ord] = flags
  end
end

CAP = 0x01
BIN = 0x02
OCT = 0x04
DEC = 0x08
HEX = 0x10
B36 = 0x20

set "_",                      "IDENTIFIER", B36 | HEX | DEC | OCT | BIN
set "01",                     "IDENTIFIER", B36 | HEX | DEC | OCT | BIN | CAP
set "234567",                 "IDENTIFIER", B36 | HEX | DEC | OCT | CAP
set "89",                     "IDENTIFIER", B36 | HEX | DEC | CAP
set "ABCDEF",                 "IDENTIFIER", B36 | HEX | CAP
set "GHIJKLMNOPQRSTUVWXYZ",   "IDENTIFIER", B36 | CAP
set "abcdef",                 "IDENTIFIER", B36 | HEX
set "ghijklmnopqrstuvwxyz",   "IDENTIFIER", B36

set " ",                      "SPACE"
set "\n",                     "NEWLINE"
set "~!@$%^&*-+=|\\:;<,>.?/", "OPERATOR"
set "[({})]",                 "BRACKET"
set "#",                      "COMMENT"
set "\"'`",                   "QUOTE"

def txt(c)
  return "DEL" if c == 127
  $codes[c.ord] || c.chr
end
