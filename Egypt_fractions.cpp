#include <iostream>
#include <vector>
using namespace std;

int GCF(int larger, int smaller){ 
	if(larger % smaller == 0){
		return smaller;
	}
	return GCF(smaller, larger % smaller);
}

vector<int> Simplify(int num, int den){
	int gcf = GCF(den, num);
	return {num / gcf, den / gcf};
}

vector<int> SubtractFrac(int num1, int den1, int num2, int den2){
	int outnum = num1 * den2 - num2 * den1;
	int outden = den1 * den2;
	return Simplify(outnum, outden);
}



vector<int> EgyptFrac(int num, int den) {
	int newDen = 2;
	int leftNum = num;
	int leftDen = den;
	vector<int> fractions;
	while (true){
		if (leftNum == 1){
			fractions.push_back(leftDen);
			return fractions;
		}
		while (true){
			if(leftDen < leftNum * newDen){
				break;
			}
			//cout << "counting... " << endl;
			newDen += 1;
		}
		fractions.push_back(newDen);
		//cout << "out" << endl;
		vector<int> diff = SubtractFrac(leftNum, leftDen, 1, newDen);
		leftNum = diff[0];
		leftDen = diff[1];
	}
}

int main(){
	cout << "Input the fraction you want to convert into an Egyptian fraction.(The integer values may overflow.)" << endl;
	int num = 0;
	cin >> num;
	cout << "------" << endl;
	int den = 0;
	cin >> den;
	vector<int> fractions = EgyptFrac(num, den);
	for (int i = 0; i < static_cast<int>(fractions.size()); i ++){
		cout << fractions[i] << ", ";
	}
	cout << "are the denominators of the Egyptian fraction.";
}
