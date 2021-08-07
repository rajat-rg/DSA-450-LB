import java.util.Scanner;
public class MyString{
    public static void main(String args[])
    {
        String str;
       Scanner scanner = new Scanner(System.in);
       str = scanner.nextLine();
       powerSet(str,0,"");
       System.out.println("\n");
       palindrome(str,0,str.length()-1);
       
       
       scanner.close(); 
    }

    private static void powerSet(String str,int n,String cur)
    {
        if(n == str.length())
        {

            System.out.print(cur+", ");
            return ;
        }
        powerSet(str, n+1, cur + str.charAt(n));
        powerSet(str, n+1, cur );

    }
    private static void palindrome(String str,int l, int r)
    {
        if(l==r)
        {
            System.out.print(str+", ");
            return;
        }

        for(int i=l;i<r;i++)
        {
            str = swap(str,l,r);
            palindrome(str, l+1, r);
            str = swap(str,l,r);
        }

    }
    private static String swap(String str, int l,int r)
    {
        char temp =  str.charAt(l);
        str = str.replace(str.charAt(l), str.charAt(r));
        str = str.replace(str.charAt(r), temp);
        return str;
        
    }

}