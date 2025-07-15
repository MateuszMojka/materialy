# przygotował: mgr inż. Mateusz Mojka
# na potrzeby wykładu dla Wyższej Szkoły Kształcenia Zawodowego

# funkcja partycjonuje - dzieli elementy na mniejsze
# i większe lub równe w odniesieniu do pivot
def partition(arr, low, high):

    # wyznaczamy pivot na ostatni element tablicy
    pivot = arr[high]

    # ustalamy index na który ma być przesunięty elementy mniejsze
    # od pivot - początkowo jest to wartość spoza zakresu tablicy
    i = low - 1

    # w pętli porównujemy elementy i przesuwamy mniejsze od pivot
    # na początek tablicy

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)

    # przenosimy pivot tak by znazł się między elementami mnieszymi
    # i większymi bądź równymi
    i += 1
    swap(arr, i, high)
    return i

# funkcja zamienia miejscami dwa elementy w tablicy
def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

#funkcja sortująca Quick Sort
def quickSort(arr, low, high):
    # warunek graniczy - wykonuj dopóki tablica ma więcej
    # niż jeden element (jeden element jest domyślnie posortowany)
    if(high > low):
        
        # index elementu pivot po partycjonowaniu
        pi = partition(arr, low, high)

        # rekurencyjne wywołanie dla elementów większych
        # i mniejszych niż pivot
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

if __name__ == "__main__":
    # tablica nieposortowana
    arr = [5, 7, 2, 1, 6, 4, 3]

    # długość tablicy 
    n = len(arr)

    # wywołanie funkcji quickSort - parametr high jest równy
    # długości tablicy - 1 
    quickSort(arr, 0, n-1)

    # wyświetlenie posortowanej tablicy 
    for val in arr:
        print(val, end=" ")
