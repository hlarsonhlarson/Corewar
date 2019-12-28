.name "Bazou"
.comment "C'est comme un petit lapin mais en plus peureux et avec des moins grandes oreilles."

fork %3
live %-1
fork %0
aff r1
ld %80, r2
sti r2, -3, %400
aff r2
