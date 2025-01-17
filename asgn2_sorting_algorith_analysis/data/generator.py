import os
import random

subdirectory = "asgn2_sorting_algorith_analysis\data\samples"
os.makedirs(subdirectory, exist_ok=True)

n = 10000

for i in range(1, n + 1):
    random_integers = [random.randint(1, 100) for _ in range(i)]

    fileName = f"file{i}.txt"
    filePath = os.path.join(subdirectory, fileName)

    with open(filePath, "w") as file:
        file.write("\n".join(map(str, random_integers)))
    
    print(fileName,'created')

print(f"Created {n} files in the '{subdirectory}' directory.")