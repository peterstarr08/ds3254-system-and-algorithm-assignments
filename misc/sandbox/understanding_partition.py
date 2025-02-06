import random

def generate_random_array(size, lower=0, upper=12):
    return [random.randint(lower, upper) for _ in range(size)]

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    print(f"Initial Array: {arr}")
    print(f"Pivot: {pivot} (Index {high})\n\n")
    
    for j in range(low, high):
        print(f"\n--------------------------------\nChecking element {arr[j]} at j = {j}, i = {i}")
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            print(f"Swapped {arr[i]} and {arr[j]} -> {arr}")


            print(arr)
        else:
            print(arr)
            print("No swap needed\n-------------------------------\n")
       
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    print(f"Final Swap (Placing Pivot): {arr}")
    print(f"Partition Index: {i + 1}\n")
    return i + 1

if __name__ == "__main__":
    arr = generate_random_array(10)
    print(f"Original Array: {arr}\n")
    partition(arr, 0, len(arr) - 1)
    print(f"Partitioned Array: {arr}")
