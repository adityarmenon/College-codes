def sort(a):
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if a[i]>a[j]:
                a[i] ,a[j] = a[j],a[i]
    return a

numbers = list(map(int, input("Enter the  numbers:").split()))
a = sort(numbers)
print("The sorted numbers are: ", a)