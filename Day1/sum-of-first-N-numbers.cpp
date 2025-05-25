// Given an integer N, return the sum of first N natural numbers.

int NnumbersSum(int N){
        int result = 0;
  for (int i = 1; i <= N; i++) {
            result += i;
        }
        return result;
}
