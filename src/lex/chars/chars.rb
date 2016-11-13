#! /usr/bin/env ruby

$types = ['INVALID'] * 128
$names = %w(NUL SOH STX ETX EOT ENQ ACK BEL BS HT LF VT FF CR SO SI DLE DC1 DC2 DC3 DC4 NAK SYN ETB CAN EM SUB ESC FS GS RS US)
$flags = ["0   | 0   | 0   | 0   | 0     | 0     | 0"] * 128

def set(str, type, flags = nil)
  str.chars.each do |c|
    $types[c.ord] = type
    $flags[c.ord] = flags if flags
  end
end

set "_",                      "IDENTIFIER", "0   | 0   | 0   | 0   | CONST | LOCAL | 0"
set "01",                     "NUMBER",     "BIN | OCT | DEC | HEX | CONST | LOCAL | CLASS"
set "234567",                 "NUMBER",     "0   | OCT | DEC | HEX | CONST | LOCAL | CLASS"
set "89",                     "NUMBER",     "0   | 0   | DEC | HEX | CONST | LOCAL | CLASS"
set "ABCDEF",                 "IDENTIFIER", "0   | 0   | 0   | HEX | CONST | 0     | CLASS"
set "GHIJKLMNOPQRSTUVWXYZ",   "IDENTIFIER", "0   | 0   | 0   | 0   | CONST | 0     | CLASS"
set "abcdef",                 "IDENTIFIER", "0   | 0   | 0   | HEX | 0     | LOCAL | CLASS"
set "ghijklmnopqrstuvwxyz",   "IDENTIFIER", "0   | 0   | 0   | 0   | 0     | LOCAL | CLASS"

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
