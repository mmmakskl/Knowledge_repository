def quicksort(numbers: list[int], low: int, high: int) -> None:
    if low < high:
        pivot_location = partition(numbers, low, high)
        quicksort(numbers, low, pivot_location - 1)
        quicksort(numbers, pivot_location + 1, high)


def partition(numbers: list[int], low: int, high: int) -> int:
    pivot = numbers[high]
    left_wall = low - 1
    for i in range(low, high):
        if numbers[i] <= pivot:
            left_wall += 1
            numbers[i], numbers[left_wall] = numbers[left_wall], numbers[i]
    numbers[high], numbers[left_wall + 1] = numbers[left_wall + 1], numbers[high]
    return left_wall + 1
