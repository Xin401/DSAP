#include <iostream>
#include <string>
#include <cassert>
#include <random> // For Test

class WordleLiteResult {
    public:
        WordleLiteResult(
            const std::string& answer,
            const std::string& guess);

        char operator[](size_t pos) const;

        const int Size() const { return 5; }
    private:
        unsigned char data_;
};

class WordleLite {
    public:
        static const size_t kSize = 5;
        WordleLite(std::string ans) : ans_{ans} {}
        WordleLiteResult Guess(std::string guess) const {
            assert(kSize == ans_.size());
            assert(kSize == guess.size());
            return WordleLiteResult(ans_, guess);
        }
    private:
        std::string ans_;
};


std::ostream& operator<<(std::ostream& os, const WordleLiteResult& res) {
    for (size_t i = 0; i < res.Size(); ++i) {
        os << res[i];
    }
    return os;
}

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

int main() {
    int id;
    std::cin >> id;
    void (*f[])() = { Test1, Test2, Test3, Test4, Test5 };
    f[id-1]();
}

void Test1() {
    WordleLiteResult r("THOSE", "TSKOE");
    std::cout << r[0] << std::endl; // 印出 'G'
    std::cout << r[1] << std::endl; // 印出 'Y'
    std::cout << r[2] << std::endl; // 印出 '_'
    std::cout << r.Size() << std::endl; // 印出 '5'
}

void Test2() {
    std::string answer, guess;
    std::cin >> answer;
    WordleLite w{answer};
    while(std::cin >> guess) {
        std::cout << w.Guess(guess) << std::endl;
    }
}

void Test3() { /* HIDDEN */ }
void Test4() { /* HIDDEN */ }
void Test5() { /* HIDDEN */ }

// [YOUR CODE WILL BE PLACED HERE]

#include <cmath>
WordleLiteResult::WordleLiteResult(const std::string &answer, const std::string &guess)
{
    data_ = 0;
    for (int i = 0; i < 5; i++)
    {
        if (answer[i] == guess[i])
        {
            data_ += 2 * pow(3, 4 - i);
        }
        else if (answer.find(guess[i]) != std::string::npos)
        {
            data_ += 1 * pow(3, 4 - i);
        }
        else
        {
            data_ += 0 * pow(3, 4 - i);
        }
    }
}

char WordleLiteResult::operator[](size_t pos) const
{
    int ans = 0;
    ans = static_cast<int>(data_ / pow(3, 4 - pos)) % 3;
    switch (ans)
    {
    case 0:
        return '_';
    case 1:
        return 'Y';
    case 2:
        return 'G';
    }
}