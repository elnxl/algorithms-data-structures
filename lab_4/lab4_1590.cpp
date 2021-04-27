#include <vector>
#include <algorithm>
#include <iostream>
void prefixFunction(std::string& str, std::vector <int>& vect) 
{
    int sizeOfStr = str.size();
    vect.resize(sizeOfStr, 0);
    int current;
    for (int iter = 1; iter < (int)str.size(); ++iter) 
    {
        current = vect[iter - 1];
        while (str[iter] != str[current] && current > 0)
        {
            current = vect[current - 1];
        }
        if (str[iter] == str[current])
        {
            current++;
        }
        vect[iter] = current;
    }
}
int main() 
{
    std::string str;
    std::cin >> str;
    std::vector <int> answer;
    long long otv = 0;
    for (int iter = 1; iter <= str.size(); ++iter) {

        //получаем подстроку
        std::string newStr = str.substr(0, iter);

        //переворачиваем рассматриваемую строку
        std::reverse(newStr.begin(), newStr.end());

        //считаем префикс функцию для полученной строки
        prefixFunction(newStr, answer);

        int n = newStr.size();
        int forMns = (*max_element(answer.begin(), answer.end()));

        otv += (n - forMns);
    }
    std::cout << otv;
}