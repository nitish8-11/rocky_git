make

echo text = abc123abc321123  expression = \w\w\w\d\d\d[abc][^123][12c]
./main "abc123abc321123" "\w\w\w\d\d\d[abc][^123][12c]"
echo

echo text = abc  expression = \w\w\d
./main "abc" "\w\w\d"
echo

echo text = 123  expression = \d\d\w
./main "123" "\d\d\w"
echo 

echo text = abc  expression = \w\w
./main "abc" "\w\w"
echo

echo text = abc123d  expression = \w\w\w[^3214]
./main "abc123d" "\w\w\w[^3214]"
echo

echo text = ab  expression = \w\w\w
./main "ab" "\w\w\w"
echo

echo text =ABc   expression = \w\w\w
./main "ABc" "\w\w\w"
echo

echo text = abc 1  expression =\w\w\w\s\d 
./main "abc 1" "\w\w\w\s\d"
echo

echo text = abcd12245  expression = \w\w\w\w[12245]
./main "abcd12245" "\w\w\w\w[12245]"
echo

echo text =ABCaA   expression = \w\w\w[aa]
./main "ABCaA" "\w\w\w[aa]"
echo

echo text = abcd  expression = \w[bcd
./main "abcd" "\w[bcd"

