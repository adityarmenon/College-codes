import hashlib
def has(n):
    return hashlib.md5(n.encode()).hexdigest()
    

n = input("Enter the file for hash:")
print("The hash code:", hash(n))


