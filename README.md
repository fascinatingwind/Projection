

## For find projection of point C to a line AB (points A,B) need:
create matrix and point
							
			(yB - yA, xA - xB, 	0		)  
Matrix M = 	(zB - zA, 	0	 , xA - xB	)  
			(xB - xA, yB-yA, 	zB-zA	)

			{		x, 								y, 							z 				}
			-------------------------------------------------------------------------------------
P point = { xA(yB - yA) + yA(xB - xA), xA(zB - zA) - zA(xB - xA), xC(xA - xB) + yC(yB-yA) + zC(zB - zA) }

found det of M
replace 1st column of M to point from P found det of Mx
replace 2st column of M to point from P found det of My
replace 3st column of M to point from P found det of Mz

projection point will be 
{det(Mx)/det(M), det(My)/det(M), det(Mz)/det(M)}

## Found a parameter

 					x1(x1-x2) + y1(y1-y2) + z1(z1-z2)
lambda parameter = ----------------------------------
					(x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2
