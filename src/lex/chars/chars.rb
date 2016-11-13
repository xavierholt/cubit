#! /usr/bin/env ruby

$types = ['INVALID'] * 128
$names = %w(NUL SOH STX ETX EOT ENQ ACK BEL BS HT LF VT FF CR SO SI DLE DC1 DC2 DC3 DC4 NAK SYN ETB CAN EM SUB ESC FS GS RS US)
$flags = [0] * 128

def set(str, type, flags = 0)
  str.chars.each do |c|
    $types[c.ord] = type
    $flags[c.ord] = flags
  end
end



set "_",                      "IDENTIFIER", "HEX | CONST | LOCAL | 0"
set "01",                     "IDENTIFIER", "BIN | CONST | LOCAL | CLASS"
set "234567",                 "IDENTIFIER", "OCT | CONST | LOCAL | CLASS"
set "89",                     "IDENTIFIER", "DEC | CONST | LOCAL | CLASS"
set "ABCDEF",                 "IDENTIFIER", "HEX | CONST         | CLASS"
set "GHIJKLMNOPQRSTUVWXYZ",   "IDENTIFIER", "0   | CONST | 0     | CLASS"
set "abcdef",                 "IDENTIFIER", "HEX         | LOCAL | CLASS"
set "ghijklmnopqrstuvwxyz",   "IDENTIFIER", "0   | 0     | LOCAL | CLASS"

set " ",                      "SPACE"
set "\n",                     "NEWLINE"
set "~!@$%^&*-+=|\\:;<,>.?/", "OPERATOR"
set "[({})]",                 "BRACKET"
set "#",                      "COMMENT"
set "\"'`",                   "QUOTE"

def txt(c)
  return "DEL" if c == 127
  $names[c.ord] || c.chr
end
