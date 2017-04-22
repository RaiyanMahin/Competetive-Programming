import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb=new StringBuffer("");
        String m="";
        int a,n;
            while((m=br.readLine())!=null) {
               String[] str=m.split(" ");
               a=Integer.parseInt(str[0]);
               n=Integer.parseInt(str[1]);
               BigInteger x=sum(BigInteger.ONE,BigInteger.valueOf(a),BigInteger.valueOf(n),BigInteger.ONE);
               sb.append(x).append("\n");
               }
            System.out.print(sb);
    }

    static BigInteger sum(BigInteger i,BigInteger n,BigInteger a,BigInteger ap){
        if(i.compareTo(n)==0)
            return i.multiply(ap).multiply(a);
        return (i.multiply(ap).multiply(a)).add(sum(i.add(BigInteger.ONE),n,a,ap.multiply(a)));
    }
}
}
