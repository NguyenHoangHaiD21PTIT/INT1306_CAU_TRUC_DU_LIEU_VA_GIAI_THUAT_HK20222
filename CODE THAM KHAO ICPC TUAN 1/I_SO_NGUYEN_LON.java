package BAI_TAP;
import java.util.*;
import java.io.*;
public class H_SO_NGUYEN_LON{
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        long tong = 0;
        while(sc.hasNext()){
            try{
                long x = Long.parseLong(sc.next());
                if(x >Integer.MAX_VALUE) tong+=x;
            } catch (Exception e){
            }
        }
        System.out.println(tong);
    }
}
