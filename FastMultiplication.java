import java.util.Scanner;
import java.math.BigInteger;

class FastMultiplication {
  public static void main(String args[]) {
    BigInteger A, B;
    Scanner reader = new Scanner(System.in);
    int T = reader.nextInt();

    while(T != 0) {
      A = reader.nextBigInteger();
      B = reader.nextBigInteger();

      BigInteger res = A.multiply(B);
      System.out.println(res.toString());
      T--;
    }
  }
}
    
