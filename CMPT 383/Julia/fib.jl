function fib(n::Int)
    if n <= 1
        return n
    end 
    arr = Int[0,1]
    for i = 3:n+1
        push!(arr, (arr[i-1] + arr[i-2]))
    end
    return arr[end]
end

function main()
    println("fib 0 => ", fib(0))
    println("fib 1 => ", fib(1))
    println("fib 2 => ", fib(2))
    println("fib 3 => ", fib(3))
    println("fib 10 => ", fib(10))
    println("fib 20 => ", fib(20))
end

main()