#include <iostream>
#include <vector>
using namespace std;

// Use long long for larger integer range
long long GCF(long long larger, long long smaller) {
    if (larger % smaller == 0) {
        return smaller;
    }
    return GCF(smaller, larger % smaller);
}

// Simplify a fraction
vector<long long> Simplify(long long num, long long den) {
    long long gcf = GCF(den, num);
    return {num / gcf, den / gcf};
}

// Subtract two fractions: num1/den1 - num2/den2
vector<long long> SubtractFrac(long long num1, long long den1, long long num2, long long den2) {
    long long outnum = num1 * den2 - num2 * den1;
    long long outden = den1 * den2;
    return Simplify(outnum, outden);
}

// Convert fraction to Egyptian fraction
vector<long long> EgyptFrac(long long num, long long den) {
    long long newDen = 2;
    vector<long long> fraction = Simplify(num, den);
    long long leftNum = fraction[0];
    long long leftDen = fraction[1];
    vector<long long> fractions;

    while (true) {
        if (leftNum == 1) {
            fractions.push_back(leftDen);
            return fractions;
        }

        while (true) {
            if (leftDen < leftNum * newDen) {
                break;
            }
            newDen += 1;
        }

        fractions.push_back(newDen);
        vector<long long> diff = SubtractFrac(leftNum, leftDen, 1, newDen);
        leftNum = diff[0];
        leftDen = diff[1];
    }
}

int main() {
    cout << "Input the fraction you want to convert into an Egyptian fraction." << endl;
    long long num, den;
    cin >> num;
	cout << "------" << endl;
	cin >> den;
    vector<long long> fractions = EgyptFrac(num, den);

    cout << "The denominators of the Egyptian fraction are: ";
    for (auto f : fractions) {
        cout << f << " ";
    }
    cout << endl;
}
