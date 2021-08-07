import java.util.Scanner;
public class MinimumElement {
    // write code here
    private static Scanner scanner = new Scanner(System.in);
    
    private static int readInteger()
    {
        int num = scanner.nextInt();
        scanner.nextLine();
        return num;
        
    }
    private static int[] readElements(int  num)
    {
        int[] array = new int[num];
        for(int i=0; i<num;i++)
        {
            array[i] = scanner.nextInt();
            scanner.nextLine();
        }
        return array;
    }
    
    private static int findMin(int[] array)
    {
        int n = array.length;
        int min = array[0];
        for(int i=1;i<n;i++)
        {
            if(array[i]<min)
            min = array[i];
        }
        return min;
        
    }
    public static void main(String[] args)
    {
        int n = readInteger();
        int[] array = readElements(n);
        int m = findMin(array);
        System.out.println(m);
    }
}