function mergeSort!(str::String)
    arr = split(str, "")
    mergeSort!(arr)
    str = ""
    for i in arr
        str *= i
    end
    return str
end


function mergeSort!(arr)
    len = length(arr)
    if len <= 1
        return arr
    end

    middle = div(len, 2)
    L = arr[1:middle]
    R = arr[middle+1:end]

    mergeSort!(L)
    mergeSort!(R)

    i = j = k = 1
    lenL = middle
    lenR = length(R)
    while i <= lenL && j <= lenR
        if L[i] < R[j]
            arr[k] = L[i]
            i += 1
        else
            arr[k] = R[j]
            j += 1
        end
        k += 1
    end

    while i <= lenL
        arr[k] = L[i]
        i += 1
        k += 1
    end
    
    while j <= lenR
        arr[k] = R[j]
        j += 1
        k += 1
    end
    return arr
end



function main()
    a = [1,9,3,2,7,6,4,8,5]
    a = mergeSort!(a)
    println("[1,9,3,2,7,6,4,8,5] => ", a)

    b = [6,2,4,8,9,5,3,1,7,10]
    b = mergeSort!(b)
    println("[6,2,4,8,9,5,3,1,7,10] => ", b)
    
    c = Int[]
    c = mergeSort!(c)
    println("[] => ", c)
    
    d = [4]
    d = mergeSort!(d)
    println("[4] => ", d)

    e = "The quick brown fox jumps over the lazy dog."
    e = mergeSort!(e)
    println("\"The quick brown fox jumps over the lazy dog.\" => ", e)

end

main()

