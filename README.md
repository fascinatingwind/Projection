## For find projection of point C to a line AB (points A,B) need:

Create matrix representation of line
![Matrix representation of line ](svg/MatrixRepresentationOfLine.svg)

Take 2 non zero rows\

Create matrix and point\
Our System of linear equation look like (M) = (P)
![Formula matrix M](svg/SLE.svg)

found det of M\
replace 1st column of M to point from P found det of Mx\
replace 2st column of M to point from P found det of My\
replace 3st column of M to point from P found det of Mz

projection point will be \
{det(Mx)/det(M), det(My)/det(M), det(Mz)/det(M)}

## Found a lambda parameter

![Formula parameter](svg/Lambda.svg)