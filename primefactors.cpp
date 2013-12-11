#include <iostream>
#include <cmath>
using namespace std;

//Tells you if a number is prime. Speaks for itself, really.
bool isPrime(unsigned int primeTest){
	//Special case for 2 since the loop further down focuses on odd numbers
	if(primeTest == 2)
		return 1;
	if(primeTest % 2 == 0)
		return 0;
	unsigned int primeSqrt = sqrt(primeTest);
	for(int i=3; i <= primeSqrt; i+=2){
		//If the number's not prime, stop and say so
		if(primeTest % i == 0){
			return 0;
		}
	}
	//If we've made it this far, the number's prime
	return 1;
}

//A basic stack using an array of 300 elements
class Stack{
	unsigned int stackContainer[300];
	public:
		int top = 0;
		void push(unsigned int x){
			this->stackContainer[this->top++] = x;
		}
		int pop(){
			unsigned int x = this->stackContainer[--this->top];
			return x;
		}
};

// This factor function uses recursion to implement a factor tree
void factor(unsigned int factorTest, Stack * factors){
	unsigned int i = 2, factorSqrt = (int)sqrt(factorTest), newFactor;
	bool foundFactor = 0;
	
	//Use brute force until we find a number that's a factor
	while(i < factorSqrt){
		if(factorTest % i == 0)
			break;
		
		if(i == 2)
			i = 3;
		else
			i+=2;
	}
	/*Push our newly discovered prime factor onto the stack, then 
	use it to find another factor. If it's not prime, factor it. 
	Otherwise, push it onto the stack. */
	factors->push(i);
	newFactor = factorTest / i;
	if(!isPrime(newFactor))
		factor(newFactor, factors);
	else
		factors->push(newFactor);
}

int main(){
	unsigned int input, size;
	Stack factors;

	cout << "What number would you like to test? ";
	cin >> input;
	if(isPrime(input)){
		cout << "It's already prime!\n";
		return 0;
	}
	factor(input, &factors);
	unsigned int current, last = 0;
	while(factors.top > 0){
		current = factors.pop();
		//if(current != last){
			cout << current << " ";
			last = current;
		//}
	}
	cout << endl;

	return 0;
}
