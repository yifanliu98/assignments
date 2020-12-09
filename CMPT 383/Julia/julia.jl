# function to calculate the volume of a sphere
function sphere_volume(r)
    return 4/3*pi*r^3    
end

# function to find the root for a quadratic funcrion
quadratic_root(a, b, delta) = ( -b + delta ) / 2a
function quadratic(a::Float64, b::Float64, c::Float64)
    delta = b^2 - 4a*c
    if delta < 0
        return Tuple[]
    end

    delta = sqrt(delta)
    x1 = quadratic_root(a, b, delta)
    if delta == 0
        return (x1)
    end

    x2 = quadratic_root(a, b, -delta)
    return (x1, x2)
end

function main()
    vol = sphere_volume(3)
    println(vol)
    println(quadratic(2.0, -2.0, -12.0))

end

main()