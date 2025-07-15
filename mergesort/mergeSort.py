# przygotował: mgr inż. Mateusz Mojka
# na potrzeby wykładu dla Wyższej Szkoły Kształcenia Zawodowego

# funkcja scala podtablice lewą i prawą do głównej tablicy
def merge(arr, left, mid, right):

    # ustalamy rozmiar tablicy lewej i prawej
    n1 = mid - left + 1
    n2 = right - mid

    # tworzymy tablice tymczasowe L (lewa) i R(prawa)
    L = [0] * n1
    R = [0] * n2

    # umieszczamy dane w tablicach tymczasowych 
    # tablica L
    for i in range(n1):
        L[i] = arr[left + i]

    # tablica R
    for j in range(n2):
        R[j] = arr[mid + 1 + j]

    i = 0
    j = 0
    k = left

    # scalamy tablice L i R
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # jeśli pozostały jakieś elementy w tablicy L
    # kopiujemy je do tablicy głównej
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
    
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


# funkcja sortująca tablicę mergeSort
# parametr left to pierwszy index tablicy
# parametr right to ostatni index tablicy
def mergeSort(arr, left, right):
    if(left < right):
        # ustal punkt podziału tablicy
        mid = (left+right) // 2

        # sortuj lewą stronę
        mergeSort(arr, left, mid)

        # sortuj prawą stronę
        mergeSort(arr, mid+1, right)

        # połącz obie tablice
        merge(arr, left, mid, right)

if __name__ == "__main__":

    # tablica nieposortowana
    arr = [5, 7, 2, 1, 6, 4, 3]

    # długość tablicy
    n = len(arr)

    # parametr right to długość tablicy-1
    mergeSort(arr, 0, n-1)

    for val in arr:
        print(val, end = " ")
    




