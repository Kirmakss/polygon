#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <chrono>
#include <iomanip>
int largestRectangleArea(std::vector<int>& heights) {
    int result = 0;
    int n = heights.size();
    std::stack<int> index_stack;
    //индексы меньшых элементов слева и справа соответсвенно
    std::vector<int> left(n, -1);
    std::vector<int> right(n, n);

    for (int i = 0; i < n; ++i){//определяем границы слева и справа для каждого столбца как самого выского
        while (!index_stack.empty() and heights[index_stack.top()] >= heights[i]){
            right[index_stack.top()] = i;
            index_stack.pop();
        }

        if (left[i] = index_stack.empty()){
            left[i] = -1;
        }else{
            left[i] = index_stack.top();
        }
        index_stack.push(i);
    }
    for (int i = 0; i < n; ++i) {
        result = std::max(result, heights[i] * (right[i] - left[i] - 1));
    }
    
    return result;
}

int maximalRectangle(std::vector<std::vector<char>>& matrix){ //функция для вычисления максимальной площади прямоугольника
    if (matrix.empty() or matrix[0].empty()) return 0; //если матрица пустая
    
    int cols = matrix[0].size();// количество колонок
    std::vector<int> heights(cols, 0);//вектор "высот" в колонках
    int max_area = 0;//максимальный прямоугольник

    //заполняем heights
    for (std::vector<char> row : matrix){
        for (int j = 0; j < cols; ++j){//проходим по каждойсроке и если есть то прибавляем 1 иначе присваиваем 0 в heigts
            if (row[j] == '1'){
                heights[j]++;
            } else{
                heights[j] = 0;
            }
        }
        //передаем получившуюся гистограмму для каждой строки
        max_area = std::max(max_area, largestRectangleArea(heights));
    }
    return max_area;
}
    int main(){
    std::srand(std::time(0));
    int rows = 500;
    int cols = 500;
    std::vector<std::vector<char>> m(rows, std::vector<char>(cols, '0'));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (std::rand() % 2 == 1){
                m[i][j] = '1';
            };
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    maximalRectangle(m);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout <<  std::fixed << std::setprecision(8) << elapsed.count() << std::endl;
}

