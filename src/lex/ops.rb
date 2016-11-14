class Op
  def initialize(n, type, name, lbp, options = {})
    @n    = n
    @type = type
    @name = name
    @lbp  = lbp
    @rpb  = options[:rbp] || lbp
    @eat  = options[:eat] || nil
  end
end

def op(type, name, lbp, options = {})
  Op.new(2, type, name,  l)
end

# Enders:
Op.new 0, :Symbol,    ")"
Op.new 0, :Symbol,    "}"
Op.new 0, :Symbol,    "]"
Op.new 0, :Symbol,    "[<]"
Op.new 0, :Symbol,    "end"

p = 0
# Joins and breaks:
Op.new 2, :Newline,   "[ ]",  p += 10
Op.new 2, :Semicolon, ";",    p += 10
Op.new 2, :Comma,     ",",    p += 10

p += 10
# Assignments:
Op.new 2, :Assign,    "=",    p, rbp: p - 1
Op.new 2, :Repoint,   "=>",   p, rbp: p - 1
Op.new 2, :Store,     "<-",   p, rbp: p - 1
Op.new 2, :Define,    ":=",   p, rbp: p - 1

# Shortcut assignments:
Op.new 2, :Assign,    "|=",   p, rbp: p - 1
Op.new 2, :Assign,    "^=",   p, rbp: p - 1
Op.new 2, :Assign,    "&=",   p, rbp: p - 1
Op.new 2, :Assign,    ">>>=", p, rbp: p - 1
Op.new 2, :Assign,    "<<<=", p, rbp: p - 1
Op.new 2, :Assign,    ">>=",  p, rbp: p - 1
Op.new 2, :Assign,    "<<=",  p, rbp: p - 1
Op.new 2, :Assign,    "-=",   p, rbp: p - 1
Op.new 2, :Assign,    "+=",   p, rbp: p - 1
Op.new 2, :Assign,    "\\=",  p, rbp: p - 1
Op.new 2, :Assign,    "%=",   p, rbp: p - 1
Op.new 2, :Assign,    "/=",   p, rbp: p - 1
Op.new 2, :Assign,    "*=",   p, rbp: p - 1
Op.new 2, :Assign,    "**=",  p, rbp: p - 1

# Miscellaneous:
Op.new 2, :Binary,    "~>",   p += 10
Op.new 2, :Binary,    "->",   p += 10
Op.new 2, :Binary,    ":",    p += 10

# Control-flow conditionals:
Op.new 2, :Binary,    "||",   p += 10
Op.new 2, :Binary,    "^^",   p += 10
Op.new 2, :Binary,    "&&",   p += 10

p += 10
# Comparisons:
Op.new 2, :Binary,    "!=",   p
Op.new 2, :Binary,    "==",   p
Op.new 2, :Binary,    "<=",   p
Op.new 2, :Binary,    ">=",   p
Op.new 2, :Binary,    "<",    p
Op.new 2, :Binary,    ">",    p

# Miscellaneous:
Op.new 2, :Binary,    "<=>",  p += 10
Op.new 2, :Binary,    "<->",  p += 10

# Boolean conditionals:
Op.new 2, :Binary,    "|",    p += 10
Op.new 2, :Binary,    "^",    p += 10
Op.new 2, :Binary,    "&",    p += 10

p += 10
# Shifts and rotates:
Op.new 2, :Binary,    ">>",   p
Op.new 2, :Binary,    "<<",   p
Op.new 2, :Binary,    ">>>",  p
Op.new 2, :Binary,    "<<<",  p

p += 10
# Addition and subtraction:
Op.new 2, :Binary,    "-",    p
Op.new 2, :Binary,    "+",    p

p += 10
# Multiplication and division:
Op.new 2, :Binary,    "*",    p
Op.new 2, :Binary,    "/",    p
Op.new 2, :Binary,    "%",    p
Op.new 2, :Binary,    "\\",   p

p += 10
# Mathy prefixes:
Op.new 1, :Prefix,    "~",    p
Op.new 1, :Prefix,    "!",    p
Op.new 1, :Prefix,    "-",    p
Op.new 1, :Prefix,    "+",    p

p += 10
# Exponentiation:
Op.new 2, :Binary,    "**",   p, rbp: p - 1

p += 10
# Typecast prefixes:
Op.new 1, :Prefix,    "%",    p
Op.new 1, :Prefix,    "?",    p
Op.new 1, :Prefix,    "&",    p

p += 10
# Some brackets:
Op.new 2, :Binary,    "[",    p, rbp: 0, eat: "]"
Op.new 2, :Binary,    "{",    p, rbp: 0, eat: "}"
Op.new 2, :Binary,    "(",    p, rbp: 0, eat: ")"

Op.new 1, :Prefix,    "[",    p, rbp: 0, eat: "]"
Op.new 1, :Prefix,    "{",    p, rbp: 0, eat: "}"
Op.new 1, :Prefix,    "(",    p, rbp: 0, eat: ")"

p += 10
# Access binaries:
Op.new 2, :Binary,    "::",   p
Op.new 2, :Binary,    ".",    p
Op.new 2, :Binary,    "$",    p
Op.new 2, :Binary,    "@",    p

p += 10
# Access prefixes:
Op.new 1, :Prefix,    "::",   p
Op.new 1, :Prefix,    "$",    p
Op.new 1, :Prefix,    "@",    p
