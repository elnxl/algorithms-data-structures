#include <vector>
#include <iostream>
#include <string>
#include <cctype>

using Vector = std::vector<int>;

#define max(x, y) (((x) > (y)) ? (x) : (y))

class Vectors : public std::vector<Vector>
{
public:
    Vectors(int value_1_1)
        : std::vector<Vector>{ 10011, Vector(2, 0) }
    {
        (*this)[0][0] = 0;
        (*this)[0][1] = 0;
        (*this)[1][0] = 0;
        (*this)[1][1] = value_1_1;
    }
};

class String : public std::string
{
public:
    void resolve(Vector& array)
    {
        int count = 0;
        for (size_t i = 0; i < size(); ++i)
        {
            if (std::isalpha((*this)[i]))
                ++count;
            else
            {
                if (count)
                    array.push_back(count);
                count = 0;
            }
        }

        if (count)
            array.push_back(count);
    }
};
std::istream& operator>>(std::istream& in, String& string)
{
    char c;
    while (std::cin.get(c)) {
        string += c;
    }
    return in;
}

int main()
{
    String input;
    std::cin >> input;

    Vector array;
    input.resolve(array);
    array.resize(10010);

    Vectors values{ array[0] };
    for (size_t k = 0; k < array.size(); ++k)
    {
        Vector& prev = values[k];
        Vector& local = values[k + 1];
        int const size = array[k];
        local[0] = max(prev[0], prev[1]);
        local[1] = prev[0] + size;
    }
    std::cout << max(values[array.size()][0], values[array.size()][1]);
    return 0;
}