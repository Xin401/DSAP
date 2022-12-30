#include <iostream>
#include <string>
#include <cassert>

class WordleLiteResult
{
public:
    WordleLiteResult(
        const std::string &answer,
        const std::string &guess);

    char operator[](size_t pos) const;

    constexpr size_t Size() const;

private:
    // sizeof(unsigned long) == 4 on PDOGS
    unsigned long data_;
};

class WordleLite
{
public:
    static const size_t kSize = 5;
    WordleLite(std::string ans) : ans_{ans} {}
    WordleLiteResult Guess(std::string guess) const
    {
        assert(kSize == ans_.size());
        assert(kSize == guess.size());
        return WordleLiteResult(ans_, guess);
    }

private:
    std::string ans_;
};

std::ostream &operator<<(std::ostream &os, const WordleLiteResult &res)
{
    for (size_t i = 0; i < res.Size(); ++i)
    {
        os << res[i];
    }
    return os;
}

int main()
{
    /*
    WordleLiteResult r("THOSE", "TSKOE");
    std::cout << r[0] << std::endl; // 印出 'G'
    std::cout << r[1] << std::endl; // 印出 'Y'
    std::cout << r[2] << std::endl; // 印出 '_'
    std::cout << r.Size() << std::endl; // 印出 '5'
    */

    std::string answer, guess;
    std::cin >> answer;
    WordleLite w{answer};
    while (std::cin >> guess)
    {
        std::cout << w.Guess(guess) << std::endl;
    }
}

// [YOUR CODE WILL BE PLACED HERE]
#include <cmath>
WordleLiteResult::WordleLiteResult(const std::string &answer, const std::string &guess)
{
    data_ = 0;
    for (int i = 0; i < 5; i++)
    {
        if (answer[i] == guess[i])
        {
            data_ += 3 * pow(10, 4 - i);
        }
        else if (answer.find(guess[i]) != std::string::npos)
        {
            data_ += 2 * pow(10, 4 - i);
        }
        else
        {
            data_ += 1 * pow(10, 4 - i);
        }
    }
}

char WordleLiteResult::operator[](size_t pos) const
{
    int ans = 0;
    ans = static_cast<int>(data_ / pow(10, 4 - pos)) % 10;
    switch (ans)
    {
    case 1:
        return '_';
    case 2:
        return 'Y';
    case 3:
        return 'G';
    }
}

constexpr size_t WordleLiteResult::Size() const
{
    return 5;
}