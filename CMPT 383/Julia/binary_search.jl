function binary_search(lst::Vector{T}, val::T) where T
    low = 1
    high = length(lst)
    while low ≤ high
        mid = (low + high) ÷ 2
        if lst[mid] > val
            high = mid - 1
        elseif lst[mid] < val
            low = mid + 1
        else
            return mid
        end
    end
    return 0
end

function searches()
    arr = [x for x in 0:2:1000000]
    for target in 0:1000000
        binary_search(arr, target)
    end
end

function main()
    @time searches()
end

main()