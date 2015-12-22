#include <iostream>
#include <random>

using namespace std;

#define LIMIT 1000000

int main()
{
    int numberOfRight = 0;
    int numberOfWrong = 0;

    //default_random_engine generator;
    random_device generator;
    cout << "Device entropy: " << generator.entropy() << endl;

    uniform_real_distribution<> distribution(0, 1);

    for (int i = 0; i < LIMIT; ++i)
    {

        double a{ distribution(generator) };
        double b{ distribution(generator) };
        double k{ distribution(generator) };

        bool myGuess; //True if i guess a>b, False if a<b

        myGuess = a > k;

        if (myGuess == a > b)
            numberOfRight++;
        else
            numberOfWrong++;
    }

    cout << numberOfRight << endl;
    cout << numberOfWrong << endl;
    cout << "Percent of right guesses: " << (double)numberOfRight / LIMIT << endl;

    return 0;
}