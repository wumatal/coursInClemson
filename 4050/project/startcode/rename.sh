# Rename all *.txt to *.text
for f in *.C; do
mv -- "$f" "${f%.C}.cpp"
done
