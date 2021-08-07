import java.util.Scanner;

public class majorityElement{
    
    public static void main(String Args[])
    {
        int n;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number\n");
        n = scanner.nextInt();
        int[] a = new int[n];
        System.out.println("Enter array numbers\n");
        for (int i = 0; i < n; i++)
        {
            a[i] =  scanner.nextInt();
        }
        int ele = findMajority(a,n);
        System.out.println("Majority element in array is "+ele);
        scanner.close();
    }
    public static int findMajority(int  a[], int n)
    {
        int ansidx = 0, count = 1;

        for(int i = 1; i<n;i++){
            if(a[i] == a[ansidx])
            {
                count++;
            }
            else
            count--;
            if (count == 0)
            {

                ansidx = i;
                count = 1;
            }
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i] == a[ansidx]){
                count ++;
            }
            if(count >n/2)
            return a[ansidx];
        }

        return -1;
    }
}