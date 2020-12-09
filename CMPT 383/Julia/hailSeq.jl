function hailSeq(n)
    next(a) = a % 2 == 0 ? div(a, 2) : 3a + 1
    result = Int[]
    while n != 1
        push!(result, n)
        n = next(n)
    end
    push!(result, 1)
    return result
end


function main()
    println("hailSeq 1 => ", hailSeq(1))
    println("hailSeq 11 => ", hailSeq(11))
    println("hailSeq 6 => ", hailSeq(6))
end

main()

