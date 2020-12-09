
function divisors(number::Int)
    result = Int[]
    for i = 2:number-1
        if number % i == 0
            push!(result, i)
        end
    end
    return result
end

function primes(n::Int)
    result = Int[]
    for i = 2:n
        if divisors(i) == []
            push!(result, i)
        end
    end
    return result
end


function main()
    println("divisors 30 => ", divisors(30))
    println("divisors 64 => ", divisors(64))
    println("divisors 127 => ", divisors(127))
    println("primes 7 => ", primes(7))
    println("primes 100 => ", primes(100))


end

main()