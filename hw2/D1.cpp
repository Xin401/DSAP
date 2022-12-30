#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class WordleLite
{
public:
    static const size_t kSize = 5;
    WordleLite(int maxNumberOfAttemps = 0) : maxNumberOfAttemps_(maxNumberOfAttemps), numberOfAttemps_()
    {
        std::cin >> ans_;
    }
    WordleLite(const WordleLite &) = delete;
    WordleLite &operator=(const WordleLite &) = delete;
    std::string Guess(std::string guess)
    {
        assert(guess.size() == kSize);
        if (numberOfAttemps_ >= maxNumberOfAttemps_)
        {
            return "ERROR";
        }
        numberOfAttemps_++;
        std::string result(5, '_');
        for (size_t i = 0; i < kSize; i++)
        {
            if (ans_[i] == guess[i])
            {
                result[i] = 'G';
            }
            else if (ans_.find(guess[i]) != std::string::npos)
            {
                result[i] = 'Y';
            }
        }
        return result;
    }

private:
    std::string ans_;
    int maxNumberOfAttemps_;
    int numberOfAttemps_;
};

class WordleLiteSolver
{
public:
    std::string Solve(WordleLite &w) const;
};

int main()
{
    int maxNumberOfAttemps;
    while (std::cin >> maxNumberOfAttemps)
    {
        WordleLite w1{maxNumberOfAttemps};
        std::cout << WordleLiteSolver().Solve(w1) << std::endl;
    }
}


string WordleLiteSolver::Solve(WordleLite &w) const
{
    string ans(5, 'a');
    int letter = 65;
    for (int i = 65; i < 91; i++)
    {
        string test(5, char(i));
        string result;
        result = w.Guess(test);
        for (int j = 0; j < 5; j++)
        {
            if (result[j] == 'G')
            {
                ans[j] = char(i);
            }
        }
    }
    return ans;
}