function join(separator::String, list::Array{String,1})
    len = length(list)
    if len == 0
        return ""
    elseif len == 1
        return list[1]
    end
    result = list[1]
    for i = 2:len
        result = result * separator * list[i]
    end
    return result
end

function main()
    # join
    println("join \", \" [\"one\",\"two\",\"three\"] => ", join(", ", ["one","two","three"]))
    println("join \"+\" [\"1\",\"2\",\"3\"] => ", join("+", ["1","2","3"]))
    println("join \"X\" [\"abc\"] => ", join("X", ["abc"]))
    println("join \"X\" [] => ", join("X", String[]))
end

main()