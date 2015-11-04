/*
Count the number of prime numbers less than a non-negative number, n.
*/

class Solution{
public:
	int countPrimes(int n){
		vector<bool> prime(n,true);
		prime[0]= false;
		prime[1] =false;
		for(int i =0;i<sqrt(n);i++){
			if(primes[i]){
				for(int j =i*i;j<n;j+=i){
					prime[j] =false;
				}
			}
		}
		return count(prime.begin(),prime.end(),true);
	}
};