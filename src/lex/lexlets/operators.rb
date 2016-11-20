class Op
  ALL = []

  attr_reader :arity
  attr_reader :name
  attr_reader :type

  def initialize(arity, type, *args)
    @arity = arity
    @type  = type
    @args  = args

    ALL << self
  end

  def name
    @args.first
  end

  def ctor
    "AST::#{@type}(lexer, #{@args.map(&:inspect).join(', ')})"
  end
end

p = 0
# Enders:
Op.new 0, :Symbol,    ")"
Op.new 0, :Symbol,    "}"
Op.new 0, :Symbol,    "]"
# Op.new 0, :Symbol,    "end",  p

# Joins and breaks:
# Op.new 2, :Newline,   "[ ]",  p += 10
constant  :Newline,           p += 10
Op.new 2, :Binary,    ";",    p += 10
Op.new 2, :Binary,    ",",    p += 10

p += 10
# Assignments:
Op.new 2, :Binary,    "=",    p, p - 1
Op.new 2, :Binary,    "=>",   p, p - 1
Op.new 2, :Binary,    "<-",   p, p - 1
Op.new 2, :Binary,    ":=",   p, p - 1

# Shortcut assignments:
Op.new 2, :Binary,    "|=",   p, p - 1
Op.new 2, :Binary,    "^=",   p, p - 1
Op.new 2, :Binary,    "&=",   p, p - 1
Op.new 2, :Binary,    ">>>=", p, p - 1
Op.new 2, :Binary,    "<<<=", p, p - 1
Op.new 2, :Binary,    ">>=",  p, p - 1
Op.new 2, :Binary,    "<<=",  p, p - 1
Op.new 2, :Binary,    "-=",   p, p - 1
Op.new 2, :Binary,    "+=",   p, p - 1
Op.new 2, :Binary,    "\\=",  p, p - 1
Op.new 2, :Binary,    "%=",   p, p - 1
Op.new 2, :Binary,    "/=",   p, p - 1
Op.new 2, :Binary,    "*=",   p, p - 1
Op.new 2, :Binary,    "**=",  p, p - 1

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
Op.new 2, :Binary,    "**",   p, p - 1

p += 10
# Typecast prefixes:
Op.new 1, :Prefix,    "%",    p
Op.new 1, :Prefix,    "?",    p
Op.new 1, :Prefix,    "&",    p

p += 10
# Some brackets:
# Op.new 2, :Binary,    "[",    p, 0, "]"
# Op.new 2, :Binary,    "{",    p, 0, "}"
# Op.new 2, :Binary,    "(",    p, 0, ")"

# Op.new 1, :Prefix,    "[",    p, 0, "]"
# Op.new 1, :Prefix,    "{",    p, 0, "}"
# Op.new 1, :Prefix,    "(",    p, 0, ")"

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

class OpTree
  attr_accessor :binary
  attr_accessor :prefix
  attr_accessor :string

  def initialize(string)
    @string   = string
    @children = Hash.new
    @binary   = nil
    @prefix   = nil
  end

  def both?
    @binary && @prefix
  end

  def each
    @children.each do |c, t|
      yield(c, t)
    end
  end

  def leaf?
    @children.empty? && !self.both?
  end

  def op
    @prefix || @binary
  end

  def [](char)
    @children[char]
  end

  def []=(char, tree)
    @children[char] = tree
  end
end

ROOT = OpTree.new('')
Op::ALL.each do |op|
  tree = ROOT
  op.name.chars.each do |char|
    tree[char] ||= OpTree.new(tree.string + char)
    tree = tree[char]
  end

  if op.arity == 2
    throw "Help!" unless tree.binary.nil?
    tree.binary = op
  else
    throw "What." unless tree.prefix.nil?
    tree.prefix = op
  end
end

def indent(depth, str)
  '  ' * depth + str + "\n"
end

def switch(tree, depth = 0)
  if tree.leaf?
    ret = indent(depth, "return new #{tree.op.ctor};")
  else
    ret = indent(depth, 'switch(lexer.peek()) {')

    tree.each do |c, t|
      ret << indent(depth, "case '#{(c == '\\')? '\\\\' : c}':")
      ret << indent(depth, '  lexer.take();')
      ret << switch(t, depth + 1)
    end

    if tree.both?
      ret << indent(depth, "case ' ':")
      ret << indent(depth, "case '\\n':")
      ret << indent(depth, "  return new #{tree.binary.ctor};")
      ret << indent(depth, 'default:')
      ret << indent(depth, '  if(lexer.spaced())')
      ret << indent(depth, "    return new #{tree.prefix.ctor};")
      ret << indent(depth, '  else')
      ret << indent(depth, "    return new #{tree.binary.ctor};")
    elsif tree.string != ''
      ret << indent(depth, 'default:')
      ret << indent(depth, "  return new #{tree.op.ctor};")
    else
      ret << indent(depth, 'default:')
      ret << indent(depth, '  throw LexError::expected(lexer, "operator");')
    end

    ret << indent(depth, '}')
  end

  return ret
end
