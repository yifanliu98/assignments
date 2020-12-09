function pythagorean(n::Int)
    result = Tuple[]
    for x = 1:n
        for y = x:n
            for z = y:n
                if x*x + y*y == z*z
                    push!(result, (x,y,z))
                end
            end
        end
    end
    return result
end

function main()
    println("pythagorean 10 => ", pythagorean(10))
    println("pythagorean 30 => ", pythagorean(30))
    
end

main()