using Printf
using Statistics

# Data types

function changeNum()
    x::Int8 = 10
    x = "Dog"
end
# changeNum()

function datatype()
    s = 0
    s = "Dog"
    println(s)
    bF=1.11111111111111
    println(bF+0.111111111111111)

    c2 = Char(120)
    println("c2: ", c2)

    i1 = UInt8(trunc(3.14))
    println("i1: ", i1)

    f1 = parse(Float64, "1")
    println("f1: ", f1)

    i2 = parse(Int8, "1")
    println("i2: ", i2)
end
# datatype()

# strings
function strings()
    s1 = "just some random words\n"
    println(length(s1))
    println(s1[1])
    println(s1[end])
    println(s1[1:4])
    s2 = string("Yifan", "Liu")
    println(s2)
    println("Yuno" * " Gasai")
    i3 = 2
    i4 = 3
    println("$i3 + $i4 = $(i3+i4)")
    s3 = """I
    have
    many
    lines"""

    println("Takao" > "Hiyama")
    println(findfirst(isequal('i'), "Keigo"))
    println(occursin("key", "monkey"))
end
# strings()

function conditions()
    age = 12
    if age >=5 && age <=6
        println("kindergarten")
    elseif age >= 7 && age <= 13
        println("middle school")
    elseif age >= 14 && age <= 18
        println("high school")
    else
        println("stay home")
    end

    @printf("true || false = %s\n", true || false ? "true" : "false")
    @printf("!true = %s\n", !true ? "true" : "false")
end
# conditions()

# loop

# i = 1
# while i < 20
#     if (i % 2) == 0
#         println(i)
#         global i += 1
#         continue
#     end
#     global i += 1 
#     if i >= 10
#         break
#     end
# end

# for i = 1:5
#     println(i)
# end

# for i in [2,4,6]
#     println(i)
# end

# for i = 1:5, j = 2:2:10
#     println((i,j))
# end

#array
function arrays()
    a1 = zeros(Int32, 2, 2)
    a2 = Array{Int32}(undef, 5)
    a3 = Float64[]
    a4 = [1,2,3]
    println(a4[1])
    println(a4[end])
    println(5 in a4)
    println(findfirst(isequal(2), a4))
    f(a) = (a >= 2) ? true : false
    println(findall(f, a4))
    println(count(f, a4))
    println(size(a4))
    println(length(a4))
    splice!(a4, 2:1, [8,9])
    println(a4)
    splice!(a4, 2:3)
    println(a4)
    println(maximum(a4))
    println(minimum(a4))
    println(a4 * 2)
    println(a4)

    a5 = [1, 3.14, "hi"]
    println(a5)
    a6 = [sin, cos, tan]
    for n in a6
        println(n(0))
    end
    a7 = [1 2 3; 4 5 6]
    for n = 1:2, m = 1:3
        @printf("%d ", a7[n,m])
    end
    println()

    println(a7[:,2])
    println(a7[2,:])
    
    a8 = collect(1:5)
    println(a8)
    a9 = collect(2:2:10)
    for n in a9 println(n) end

    a10 = [n^2 for n in a9]
    push!(a10, 36)
    println(a10)

    a11 = rand(0:9, 5, 5)
    println(a11)

end
# arrays()

# tuples value cannot be changes
function tuples()
    t1 = (1,2,3,4)
    println(t1)
    t1 = (sue = ("Sue", 100), paul = ("Paul", 23))
    println(t1.sue)

end
# tuples()





# getSum(x,y) = x + y
# x, y = 1, 2
# @printf("%d + %d = %d\n", x, y, getSum(x,y))
# println("$x + $y = $(getSum(x, y))")

# v1 = 5 
# function changeV1(n)
#     global v1 = n
# end
# changeV1(10)
# println(v1)

# function getSum2(args...)
#     sum = 0
#     for a in args
#         sum += a
#     end
#     println(sum)
# end
# getSum2(1,2,3,4)

# function next2(val)
#     return (val+1, val+2)
# end
# println(next2(5))

# # partial function
# function makeMultiplier(num)
#     return function(x) return x * num end
# end
# mult3 = makeMultiplier(3)
# println(mult3(6))

# function getSum3(num1::Number, num2::Number)
#     return num1 + num2 
# end
# function getSum3(num1::String, num2::String)
#     return parse(Int32, num1) + parse(Int32, num2)
# end
# println("5 + 4 = ", getSum3(5,4))
# println("5 + 4 = ", getSum3("5","4"))


# v2 = map(x -> x * x, [1,2,3])
# println(v2)

# v3 = map((x,y) -> x+y, [1,2], [3,4])
# println(v3)

# v4 = reduce(+, 1:100)
# println(v4)

# sentence = "This is a string"
# sArray = split(sentence)
# println(sArray)
# longest = reduce((x, y) -> length(x) > length(y) ? x : y, sArray)
# println(longest)

# @enum Color begin
#     red = 1
#     blue = 2
#     green = 3
# end
# favColor = blue::Color
# println(favColor)

# :Derek
# println(:Derek)

# struct : immutable, value unchangable

# struct Customer
#     name::String
#     balance::Float64
#     id::Int
# end

# bob = Customer("Bob Smith", 10.50, 123)
# println(bob)

# abstract type Animal end

# struct Dog <: Animal
#     name::String
#     bark::String
# end

# struct Cat <: Animal
#     name::String
#     meow::String
# end

# bowser = Dog("Bowser", "Ruff")
# muffin = Cat("Muffin", "Meow")
# function makeSound(animal::Dog)
#     println("$(animal.name) says $(animal.bark)")
# end
# function makeSound(animal::Cat)
#     println("$(animal.name) says $(animal.meow)")
# end
# function getName(animal::Animal)
#     println("$(animal.name)")
# end
# getName(bowser)
# getName(muffin)

# makeSound(bowser)
# makeSound(muffin)


############ user input

# print("Enter a number ")
# num1 = chomp(readline())
# print("Enter a number ")
# num2 = chomp(readline())

# try
#     val = (parse(Int32, num1)) / (parse(Int32, num2))
#     if val == Inf
#         error("Can't Divide by Zero")
#     else
#         println(val)
#     end
# catch e
#     println(e)
# end

function type()
    number::Int = 3
    character::Char = 'y'
    println(number)
    println(character)
end

# type()

# arr = Array{Int8,2}(undef, 3,4)
# println(arr)


# tupl = () 
# println(isempty(tupl)) 
  
# # Creating a tuple with similar values 
# tupl = (1, 2, 4, 5) 
# println(tupl) 
  
# # Creating a tuple with mixed values 
# tupl = (1, 2, 3, "Hello Geeks") 
# println(tupl)
# println(tupl[4])

# tup3 = (a = ("A", 10), b = ("B", 20))
# println(tup3[:a] == tup3.a)


function dictionary()
    d1 = Dict("pi"=>3.14, "e"=>"2.718", 1=>1)
    println(d1["pi"])
    d1["golden"] = 0.618
    delete!(d1, "pi")
    println(haskey(d1,"pi"))
    println(d1)
    println(in("pi"=>3.14))

    println(keys(d1))
    println(values(d1))

    for kv in d1
        println(kv)
    end

    for (key, value) in d1
        println(key, " : ", value)
    end

end

# dictionary()

# set : value must be unique
function set()
    st1 = Set(["Jim", "Pam", "Jim", 1])
    println(st1)
    for i in st1
        println(i)
    end

    # union, intersect, setdiff (set1, set2)

end
# set()


# partial function
function makeMultiplier(num)
    return function(x) return x * num end
end


function main()
    mult3 = makeMultiplier(3)
    println(mult3(6))
end

main()