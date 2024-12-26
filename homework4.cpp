#include <iostream>
#include <vector>
#include <unordered_set>
void test(std::vector<std::unordered_set<int>> my_otvet, std::vector<std::unordered_set<int>> ver_otvet){
    if (my_otvet == ver_otvet){
        std::cout << "Все норм" << "\n";
    }else{
         std::cout << "Что-то не то" << "\n";
    }
}
std::string dvoich(int a){//перевод в двоичную систему счисления
    std::string ot = "";
    while (a > 0){
        ot = std::to_string(a % 2) + ot;
        a = a / 2;
    }
    return ot;
}

std::vector<std::unordered_set<int>> f(std::vector<std::unordered_set<int>> sets, std::unordered_set<int> universe){
    std::vector<std::unordered_set<int>> variants;
    int col_comb = sets.size() * sets.size() - 1;//количество комбинаций
    int min_size = 2147483647;
    int len = sets.size();
     for (int i = 0; i < col_comb; ++i){//цикл по всем комбинациям
        std::unordered_set<int> universe2 = universe;//копия множетсва из которой будем убирать элементы по мере их добавления
        std::string comb_dv_str = dvoich(i); //номер данной комбинации в двоичной системе
        std::vector<char> comb_dv(len, '0');
        
        for (int j = comb_dv_str.size()-1;j>=0;--j){//переводим в нужный формат
            comb_dv[len - comb_dv_str.size() + j] = comb_dv_str[j];
        }

        std::vector<std::unordered_set<int>> sets2;// вектор с множествами которые пойдут в ответ
        for (int j = 0; j < len; ++j){//цикл по номеру комб в дв системе
            char x = comb_dv[j];
            if (x == '1'){//в данной комб это множество используется
                bool usl = false;
                for (int el_in_set : sets[j]){
                    if (universe.count(el_in_set) == 1){//если элемент в данном подмнож есть в множ, удаляем из копии множ
                        usl = true;
                        universe2.erase(el_in_set);
                    }
                }
                if (usl == true){//добавляем подходящее подмножество
                    sets2.push_back(sets[j]);
                }
            }
    }

        if (universe2.size() == 0 and sets2.size() <= min_size){//все элементы из копии были удалены и минимальное количество подмножеств
            variants = sets2;
            min_size = sets2.size();
        }
    }
     return variants;
}
//основная функция
int main(){
    f({{1, 4, 7},{9},{0, 1, 2, 6, 9},{2, 7},{3, 6},{0, 1, 2, 3, 4, 6, 7, 8, 9},{1, 3, 4},{2, 5, 8},{2, 4, 5, 7},{0, 2, 3, 6, 8},{2, 9},{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},{0, 2, 4, 5, 6, 7},{2, 3, 4, 5, 6, 7, 8, 9},{2, 9},{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},{0, 1, 2, 3, 4, 5, 7, 8, 9},{0, 3},{5},{0},{0, 2, 3, 4, 5, 6, 7, 8, 9}},{1,2,3,4,5});
}