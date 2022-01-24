// Author: Nathan N. 
// Date: Jan 22. 2022
// Description: A program that prime factorizes an given number by using recurision... 
//              ...since doing prime factorization by hand looks very similar to a tree data structure 
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
void find_prime(long number, vector<long> &factors);
void end_timer(time_t begin);
void print_vector(vector<long> vec, long original_number);
long multiply_primes(vector<long> vec);

int main() {

  cout << " /////////// Prime Factorization v1 \\\\\\\\\\\\ " << endl;
  cout << "           //////////////////////////     " << endl;
  cout << "Description: A program that prime factorizes an given number by using recurision... " << endl;
  //cout << "since doing prime factorization by hand looks very similar to a tree data structure" << endl << endl;
  cout << "****  Do not input a number greater than (1.844 * 10^18)  ****" << endl;
  cout << "Please input an positive integer greater than 1 " << endl; 
  /** for bigger terminal windows, you can uncomment this section and comment out the above section
 
  cout << "                 /////////// Prime Factorization v1 \\\\\\\\\\\\ " << endl;
  cout << "                           //////////////////////////     " << endl;
  cout << "             Description: A program that prime factorizes an given number by using recurision... " << endl;
  cout << "             since doing prime factorization by hand looks very similar to a tree data structure" << endl;
  cout << "         ****  Do not input a number greater than (1.844 * 10^18)  **** " << endl;
  cout << "             Please put an positive integer greater than 1 " << endl;    
 **/

  double input = -1;
  cin >> input;

  // keep track of the time
  time_t start = time(NULL);
    
  // check if input is improper
  if(input <= 1 || input != (long) input || input > 1.844e18 ) {
    /** this condition may not work for really long floating point values 
    such as 2.0000000000000000000000001 cuz in the computer this will 
    just be truncated to 2.000000000 **/
    cout << endl << "Please follow the instructions above. Exiting..." << endl;
    return -1;
  }
  vector<long> primes;
  find_prime(input,primes);
  print_vector(primes,input);


  end_timer(start); 

}

void end_timer(time_t begin) {
  time_t end = time(NULL);
  cout << endl << "** Finshed in: " << end - begin << " seconds **" << endl << endl;
}

void find_prime(long number, vector<long> &factors) {
  /** First try at getting this function to work properly...
      ...it didn't work cuz I was looking for multiple factors for each number rather than just finding one factor and branching out from there) 


  long i = number-1;
  for(i; i > 1; --i){

    double checking = ( number / ((double) i) );
    // helps catch any factors of the function parameter "number"
    // (aka if this if clause is true, than the current number is a factor of the orginal input but is not prime)
    if (checking == (long) checking)  {
      //long prime_factor = 
      find_prime(i, &factors);
      continue;
      //cout << i << " is a factor" << endl;
 
    }
  }
  // should only be added if the number is prime
  factors.push_back(number);
  return 0;
  
  return number;
**/

// Step 1: Loop thru all the integers less than our current number


  // the for loop used to be: for(long i = number-1; i > 1; --i), but time tests showed this was really slow...
    // ... the reason being that we just needed to find one factor of an given number; it is more likely to find an factor 
    // ..that is in the smaller number range rather than the bigger number range (since every bigger number is really made up more so with smaller numbers rather than really large numbers)
    // ... once we find just one factor, the rest becomes easy cuz we can rely on the magic of division and recursion 
    // ...hte difference in execution time doesn't matter for small inputs, but it does matter for really really large inputs (because the number of steps to execute is much less)
 //for(long i = number-1; i > 1; --i) {
 for(long i = 2; i < number - 1; ++i){
   double other_factor = ( number / ((double) i) );
    // Try to find just one factor of the current number
    if (other_factor == (long) other_factor)  {
      // check if that factor is prime (condition: recursion where the number is only divisble by one and itself)
      // (aka this clause should not be triggered if the current number in question is prime)
      find_prime(i, factors);
      find_prime(other_factor, factors);
      return;
    }
      /** the above if statement in puesdocode:

        // if number is not prime, then repeat step 1
        // else, add that factor to vector (because the number must be prime) **/
    }
// should only be added if the number is prime
factors.push_back(number);
return;
}
// since we are not modifying vectors, we don't need to pass by reference
void print_vector(vector<long> vec, long original_number) {
    for(long j = 0; j < vec.size(); j++) {
        // print each prime factor
        if (j != vec.size() - 1) {
            cout << vec[j] << " " << "* ";
        }
        else{
            // print last element in the prime vector
            long multiplied = multiply_primes(vec);
            cout << vec[j] << " = " << multiplied << endl;
                if(vec.size() == 1) {
                      cout << endl  << (long) original_number << " is a prime number !!" << endl;
                }
                else{
                    // serves as a check for whether the output is correct and can be trusted
                    if( multiplied == original_number ){
                        cout << "Prime factorization is DEFINTELY correct ! (Checked by program)" << endl;
                    }
                    else {
                        
                        cout << "Something went wrong..." << endl;
                    }
                }
        }
    }
}
// multiplies all the elements in the vector of prime numbers
long multiply_primes(vector<long> vec) {
    long total = 1;
    for(long j = 0; j < vec.size(); j++) {
        total = total * vec[j];
    }
    return total;
}

