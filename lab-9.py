import numpy as np
#два массива для теста
arr1 = np.array([1, 2, 3, 4, 5])
arr2 = np.array([5, 4, 3, 2, 1])

#unique возвращает уникальные элементы массива в сортированном порядке
#array_equal поэлементно проверяет равны ли два массива и одинаковый ли порядок
otvet = np.array_equal(np.unique(arr1), np.unique(arr2))

print("Содержат одинаковые элементы:", otvet)
