#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void test(std::vector<short int> arr_vyvod,std::vector<short int>& arr_otvet){
    bool usl = true;
    for (size_t i = 0; i < arr_vyvod.size(); ++i){
        if (arr_vyvod[i] != arr_otvet[i]){
            usl = false;
        }
    }
    std::cout << "Размер bool usl: " << sizeof(usl) << "\n"; //1
    std::cout << "Размер std::vector<short int> arr_vyvod(копия в тесте): " << sizeof(arr_vyvod) << "\n"; //ссылкой передать не получается, выдает ошибку
    if (usl){
        std::cout << "Все прекрасно"<< "\n" << "\n"; 
    } else{
        std::cout << "Что-то не то"<< "\n" << "\n"; 
    }
}

vector<short int> f(int size, std::vector<std::string>& arr){
    std::vector<short int> arr_vyvod(size,0);//массив на вывод такого же разммера как первый
    std::unordered_map<std::string,short int> unique;//список уникальных знач масссива
    for (int i = 0; i < size; ++i){
        if (unique.count(arr[i]) == 0){//условие если такого знач нет, то создаем
            unique[arr[i]] = 1;

        } else {//если есть то прибавляем к количеству
            unique[arr[i]]++;
        }
    }
    for (int i = 0; i < size; ++i){//заполнение массива на выход значениями из словаря
        arr_vyvod[i] = unique[arr[i]];
    }

    std::cout << "Размер int size: " << sizeof(size) << "\n";
    std::cout << "Размер std::vector<short int> arr_vyvod: " << sizeof(arr_vyvod) <<"\n";
    std::cout << "Размер std::vector<std::string> arr : " << sizeof(arr) << "\n";
    std::cout << "Размер std::unordered_map<std::string,short int> unique : " << sizeof(unique) << "\n";
    return arr_vyvod;
}
int main(){
    std::vector<std::string> ar = {"abcdabcdabcdabcdabcd","abcdabcdabcdabcdabcd","abcdabcdabcdabcdabcd","2","3","3","4","5"};
    std::vector<short int> ar2 = {3,3,3,1,2,2,1,1};
    test(f(8,ar),ar2);

    ar.resize(1);
    ar2.resize(1);
    ar = {"a"};
    ar2 = {1};
    test(f(1,ar),ar2);

    ar.resize(6);
    ar2.resize(6);
    ar = {"a","a","a","b","b","b"};
    ar2 = {3,3,3,3,3,3};
    test(f(6,ar),ar2);

    ar = {"1","2","3","4","5","6"};
    ar2 = {1,1,1,1,1,1};
    test(f(6,ar),ar2);

    ar = {"1","2","3","4","5","6"};//проверка самого теста должно выдать неверно
    ar2 = {1,1,1,1,1,3};
    test(f(6,ar),ar2);
}
