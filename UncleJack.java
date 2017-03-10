import java.util.Scanner;
import java.math.BigInteger;

class UncleJack {
  public static void main(String args[]) {
    Scanner reader = new Scanner(System.in);
    while(true) {
      BigInteger N;
      int K;
      N = reader.nextBigInteger();
      K = reader.nextInt();
      if(N.signum() == 0 && K==0) break;
      
      BigInteger ans = N.pow(K); 
      System.out.println(ans.toString());
    }
  }
}
