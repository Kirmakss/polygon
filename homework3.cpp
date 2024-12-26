#include <iostream>
#include <stack>
using namespace std;

//O(1)
void test(std::string vyvod,std::string otvet){
    if (vyvod == otvet){
        cout << "Вроде норм" << "\n"; 
    }else{
        cout << "Все плохо" << "\n";
    }
}

// O(n)
std::string f(std::string stroka){
    //int c = 0;//счетчик скобок
    int len = stroka.size();//длинна строки
    stack <char> stack_stroka;

    for (int i = 0; i < len; ++i){//цикл по строке
        if (stroka[i] == '('){
            stack_stroka.push(1);//добавляем в стек т.к. скобка открылась
        }else if(stroka[i] == ')'){
            if (stack_stroka.empty() == true){//если есть закрывающая скобка без/до открывающей, то сразу можем сказать, скобки неверные
                return "неверные скобки";
            }else{
                stack_stroka.pop();//удаляем из стека т.к. скобка закрылась
            }
        }
    }
    if (stack_stroka.size() == 1){//осталась одна открывающая
        return "true";
    }else if(stack_stroka.empty() == true){//все скобки зкрыты
        return "false";
    }else{
        return "неверные скобки";
    }
}
int main(){
    test(f("aasjhvw"),"false");
    test(f("(as()("),"неверные скобки");
    test(f(")asknx("),"неверные скобки");
}

