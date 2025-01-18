#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <random>
int splitArray(std::vector<int>& nums, int k){
    int minMax = 0;
    int sum = 0;
    //ищем максимум и сумму
    for (int num : nums){
        minMax = std::max(minMax, num);
        sum += num;
    }

    auto splitting = [&](int maxSum){
        int cumulativeSum = 0;
        int parts = 1;
        for (int num : nums){
            cumulativeSum += num;//добавляем к общей сумме
            if (cumulativeSum > maxSum){//если суммма превышает максимум начинаем заново
                cumulativeSum = num;
                parts++;
            }
        }
        //если полученное количество меньше k возвращаем true
        return parts <= k;
    };

    //ищем минимально возможную сумму с которой можем разделить на k подмассивов бинарным поиском
    while (minMax < sum){
        int mid = (minMax + sum) / 2;
        if (splitting(mid)){//если разделение возможно ищем слева
            sum = mid;
        } else{//иначе справа
            minMax = mid + 1;
        }
    }

    return minMax;
}
std::vector<int> generateVector(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);
    std::vector<int> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(dist(gen));
    }
    return result;
}
int main(){
    std::srand(std::time(0));
    std::vector<int> V = generateVector(2500);
    auto start = std::chrono::high_resolution_clock::now();
    int ot = splitArray(V, 10);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout <<  std::fixed << std::setprecision(8) << elapsed.count() << std::endl;
    int mx = 0;
    int sm = 0;
    for (int num : V){
        mx = std::max(mx, num);
        sm += num;
    }
    //1771.5   0.00001810
    std::cout << 2500 * std::log(sm-mx);
}
