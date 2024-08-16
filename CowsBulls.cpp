#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

struct Position
{
    int wp;
    int rp;
};

void CheckPosition(const std::vector<int>& cypher, const std::vector<int>& inp)
{
    Position check{0, 0};
    for (int i = 0; i < 4; i++)
    {
        if (inp[i] == cypher[i])
        {
            check.rp += 1;
        }
        else if (std::find(cypher.begin(), cypher.end(), inp[i]) != cypher.end())
        {
            check.wp += 1;
        }
    }
    std::cout << "Верных чисел на верных местах: " << check.rp << "\nВерных чисел на неверных местах: " << check.wp << "\n";
}

void SplitInput(std::vector<int>& out, int inp)
{
    out.clear();
    while (inp > 0)
    {
        out.insert(out.begin(), inp%10);
        inp/=10;
    }
}

void Print(const std::vector<int>& inp)
{
    for (size_t i = 0; i < inp.size(); i++)
    {
        if (i)
        {
            std::cout << " ";
        }
        std::cout << inp[i];
    }
    std::cout << "\n";
    return;
}

void GenerateCypher(std::vector<int>& cypher)
{
    cypher = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    srand(time(0));
    std::random_shuffle(cypher.begin(), cypher.end());
    cypher.erase(cypher.begin()+4, cypher.end());
}

int main()
{
    std::vector<int> cypher, input;
    GenerateCypher(cypher);
    //Print(cypher);
    
    std::cout << "Введите комбинацию:\n";
    int count = 10;
    while (input != cypher && count > 0)
    {
        std::cout << "Осталось " << count << " ходов\n";
        int inp;
        std::cin >> inp;
        SplitInput(input, inp);
        //Print(input);

        CheckPosition(cypher, input);
        count -= 1;
    }
    if (count > 0)
        std::cout << "Код верный!\n";
    else
        std::cout << "Вы проиграли!";
}