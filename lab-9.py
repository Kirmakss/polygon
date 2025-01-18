import numpy as np
#два массива для теста
arr1 = np.unique(np.array([1, 2, 3, 4, 5]))
arr2 = np.unique(np.array([5, 4, 3, 2, 1,7,8,7,1]))

#unique возвращает уникальные элементы массива в сортированном порядке
#intersect1d возвращает пересечение

otvet = np.intersect1d(arr1,arr2)
print("Содержат одинаковые элементы:", otvet)
