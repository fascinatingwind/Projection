

## For find projection of point C to a line AB (points A,B) need:
create matrix and point

![Formula matrix M and point P](./MatrixM.svg)

found det of M
replace 1st column of M to point from P found det of Mx
replace 2st column of M to point from P found det of My
replace 3st column of M to point from P found det of Mz

projection point will be 
{det(Mx)/det(M), det(My)/det(M), det(Mz)/det(M)}

## Found a parameter

![Formula parameter](./Lambda.svg)