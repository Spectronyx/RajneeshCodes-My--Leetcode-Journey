// brute force method with optimization
// class Solution {
// public:
//     bool isPrime(int num){
//         if(num <= 1) return false;
//         if(num == 2) return true;

//         for(int i = 3;i*i <= num;i += 2){
//             if(num%i == 0){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int countPrimes(int n) {
//         int count = 1;
//         if(n <= 2 ) return false;

//         for(int i = 3;i < n;i += 2){
//             if(isPrime(i)){
//                 count++;
//             }
//         }
//         return count;
//     }
// };


// using the sieve of erastrothenis
// class Solution {
// public:
//     int countPrimes(int n){
//         // handle the edge case;
//         if(n <= 2) return 0;

//         // boolean array lo aur sabko prime man lo
//         vector<bool> isPrime(n,true);

//         isPrime[0] = false;
//         isPrime[1] = false;

//         // Sieve logic - multiples ko false mark kar do
//         for(int i = 2;i*i <= n;i++){
//             if(isPrime[i]){
//                 // agar i prime h to uske sare multiple ko false mark;
//                 // start from i*i because usse chhote sab mark hai;

//                 for(int j = i*i; j < n;j += i){
//                     isPrime[j] = false;
//                 }
//             }
//         }
//         int count = 0;
//         for(auto i: isPrime){
//             if(i == true) count++;
//         }
//         return count;
//     }
// };


// using optimzed sieve
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        
        // vector<int> sabse safe hai
        vector<int> isPrime(n, 1);  // 1 = prime, 0 = not prime
        
        isPrime[0] = isPrime[1] = 0;
        
        for(int i = 2; i * i < n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        
        int count = 0;
        for(int i = 2; i < n; i++) {
            count += isPrime[i];  // Direct addition (1 for primes)
        }
        
        return count;
    }
};