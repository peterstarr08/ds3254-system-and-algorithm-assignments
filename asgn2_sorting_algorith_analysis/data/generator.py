import os
import random

subdirectory = "asgn2_sorting_algorith_analysis/data"
os.makedirs(subdirectory, exist_ok=True)

output_file = os.path.join(subdirectory, "random_arrays.txt")

n = 5000

print(f"Creating a single file with {n} arrays...Please wait, it may take a while.")

with open(output_file, "w") as file:
    for i in range(1, n + 1):
        random_integers = [random.randint(1, 100) for _ in range(i)]
        file.write(" ".join(map(str, random_integers)) + "\n") 
        print(f"\rProgress: {i} of {n} arrays created", end="")


print(f"\nCreated a single file with {n} arrays in the '{output_file}' file.")