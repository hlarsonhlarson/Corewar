.name "Bazou"
.comment "C'est comme un petit lapin mais en plus peureux et avec des moins grandes oreilles."

ld %90, r3
ld %20, r4
st r4, r6
sub r3, r6, r5
live %-1
fork %-30
aff r5
