#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    if (number == 3) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main(void) {

    int i = 0;
    int j = 0;
    ofstream file;
    file.open("twin_primes.txt");

    while (j <= 1000000) {
        if (isPrime(i) && isPrime(i+2)) {
            file << i << ", " << i+2 << endl;
            i += 2;
            j++;
            continue;
        }
        i++;
    }

    file.close();

    return 0;
}