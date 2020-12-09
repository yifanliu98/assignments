det a b c = b^2 - 4*a*c
quadsol1 a b c = (-b - sqrt (det a b c))/2*a
quadsol2 a b c = (-b + sqrt (det a b c))/2*a

third_a list = list !! 2
third_b (a:b:c:rest) = c

hailstone n
    | (even n) = (div n 2)
    | (odd n) = 3 * n + 1