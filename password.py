def st(p):
    length = len(p) >= 8
    upper = any(char.isupper() for char in p)
    lower = any(char.islower() for char in p)
    digit = any(char.isdigit() for char in p)
    special = any(char in "!@#$&*()_+" for char in p)
    stre = sum([length, upper, lower, digit, special])
    if stre == 5:
        return "Strong"
    elif stre < 5:
        return "weak"
    else:
        return "Invalid Password"


p = input("Enter the password:")
print("Password Strength:", st(p) )