def pseudo_random_number(seed_value):
    random.seed(seed_value)
    return random.randint(1, 100)

seed = int(input("Enter a seed value for pseudo-random number generation: "))
print("Pseudo-Random Number:", pseudo_random_number(seed))