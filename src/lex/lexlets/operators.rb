$U = {}
$B = {}
$p = 1000

def binary(name)
  $B[name] = $p
end

def unary(name)
  $U[name] = $p
end

def group(name = nil)
  yield
  $p -= 10
end

group "Unary Lookup" do
  unary '@'
  unary '$'
  unary '::'
end

group "Binary Lookup" do
  binary '@'
  binary '$'
  binary '.'
  binary '::'
end

group "Type Unaries" do
  unary '&'
  unary '?'
end

group "Exponential" do
  binary '**'
end

group "Common Unaries" do
  unary '+'
  unary '-'
  unary '!'
  unary '~'
end

group "Multiplicative" do
  binary '*'
  binary '/'
  binary '%'
  binary '\\'
end

group "Additive" do
  binary '+'
  binary '-'
end

group "Shift and Rotate" do
  binary '<<'
  binary '>>'
  binary '<<<'
  binary '>>>'
end

group {binary '&'}
group {binary '^'}
group {binary '|'}

group {binary '<->'}
group {binary '<=>'}

group "Comparisons" do
  binary '>'
  binary '<'
  binary '>='
  binary '<='
  binary '=='
  binary '!='
end

group {binary '&&'}
group {binary '^^'}
group {binary '||'}

group {binary ':'}

group {binary '->'}
group {binary '~>'}

group "Assignment" do
  binary '='
  binary '=>'
  binary ':='

  binary '**='
  binary '*='
  binary '/='
  binary '%='
  binary '\\='
  binary '+='
  binary '-='

  binary '<<='
  binary '>>='
  binary '<<<='
  binary '>>>='

  binary '&='
  binary '^='
  binary '|='
end

# group {unary  'not'}
# group {binary 'and'}
# group {binary 'xor'}
# group {binary 'or'}

group {binary ','}
group {binary ';'}
group {binary "\n"}
