#include <stdexcept>
#include <vector>
#include "./constants.cpp"
#include "./helpers.cpp"


using namespace std;

void checkArgs(int argc, char* argv[], vector<string> checks) {

  for(int i=0; i<=checks.size(); i++) {
    string check = checks[i];

    // Argument is not a number
    if(check == IS_NUMBER) {
      if(isNumber(string(argv[1])) == false) {
        throw invalid_argument("Veuillez entrer un nombre entier.");
      }
    }

    // Argument is not a prime number
    if(check == IS_PRIME_NUMBER) {
      if(!isPrimeNumber(atoi(argv[1]))) {
        throw invalid_argument("Veuillez entrer un nombre premier.");
      }
    }

    // Only one argument is allowed
    if(check == ONLY_ONE_ARGUMENT) {
      if(argc > 2) {
        throw invalid_argument("Veuillez entre un seul argument.");
      }
    }

    // At least one argument 
    if(check == AT_LEAST_ONE_ARGUMENT) {
      if(argc == 1) {
        throw invalid_argument("Veuillez entrer un argument.");
      }
    }

    // At least two argument 
    if(check == AT_LEAST_TWO_ARGUMENTS) {
      if(argc <= 2) {
        throw invalid_argument("Veuillez entrer au moins deux arguments.");
      }
    }

    // Only strings allowed
    if(check == ONLY_STRINGS) {
      for(int j=1; j<=argc-1; j++) {
        if(isNumber(argv[j])) {
          throw invalid_argument("Veuillez entrer un string.");
        }
      }
    }

    // only integers
    if(check == ONLY_INTEGERS) {
      for(int j=1; j<=argc-1; j++) {
        if(false == isNumber(argv[j])) {
          throw invalid_argument("Veuillez entrer que des entiers.");
        }
      }
    }

    // Only two arguments
    if(check == ONLY_TWO_ARGUMENTS) {
      if(argc != 3) {
        throw invalid_argument("Veuillez entrer exactement 2 arguments.");
      }
    }

  }
}