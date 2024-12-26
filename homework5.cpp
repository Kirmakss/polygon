#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>

void sort_1(std::vector<int>& mass){//пузырек
    int len = mass.size();
    for (int i = 0; i < len-1; ++i){
        for (int j = 0; j < len - i - 1; ++j){
            if (mass[j] > mass[j + 1]){
                std::swap(mass[j], mass[j+1]);
            }
        }
    }
}

int partition(std::vector<int> &mass, int start, int end){
    int mid_index = start + (end - start) / 2;
    int mid_value = mass[mid_index];//центральный элемент массива
    int i = start, j = end;
    int temp;
    while(i <= j){//деление массива
        while(mass[i] < mid_value) {//ищем элемент который нужно перекинуть в левую часть
            i++;
        }
        while(mass[j] > mid_value) {//в правую часть
            j--;
        }
        if(i <= j) {//меняем местами
            temp = mass[i];
            mass[i] = mass[j];
            mass[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}
void sort_2(std::vector<int> &mass, int start, int end){//быстрая сортировка
    if(start < end) {
        int pivotIndex = partition(mass, start, end);
        sort_2(mass, start, pivotIndex - 1);//"Левый кусок"
        sort_2(mass, pivotIndex, end);//"Првый кусок"
    }
}

void sort_3(std::vector<int>& mass){//сортировка подсчетом
    int n = mass.size();

    //ищем максимальный элемент
    int k = 0;
    for (int i = 0; i < n; i++){
        k = std::max(k, mass[i]);
    }

    std::vector<int> output(n,0);//заполняем массив размера n(размер сортируемого массива) нулями 
    std::vector<int> count(k + 1, 0);//заполняем массив размера k+1(максимальное значение) нулями 

    //считаем количество каждого уникального значения 
    for (int i = 0; i < n; i++){
        count[mass[i]]++;
    }

    //ищем общее количество 
    for (int i = 1; i <= k; i++){
        count[i] += count[i - 1];
    }
    //ищем индексы кажого эл исходного массива в count
    for (int i = n - 1; i >= 0; i--){
        output[count[mass[i]] - 1] = mass[i];
        count[mass[i]]--;
    }

     //копируем отсортированное в массив
    for(int i=0; i < n; ++i){ 
        mass[i] = output[i]; 
    }
}

int main(){
    std::ofstream out;
    out.open("box.txt");

    std::srand(std::time(0));
    std::vector<int> t(1000000);
    for(int i = 0; i<50;i++){
        for (int &val : t) {
            val = std::rand() % 101;
        }

        auto start = std::chrono::high_resolution_clock::now();
        //vector x = countSort(t);
        sort_2(t,0,999999);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        out <<  std::fixed << std::setprecision(8) << elapsed.count() << std::endl;
        //std::cout << "Время выполнения: " << std::fixed << std::setprecision(8) << elapsed.count() << " секунд" << std::endl;
    }
    out.close();
    //  for (int i : t){
    //      std::cout << i << " ";
    //  }
}