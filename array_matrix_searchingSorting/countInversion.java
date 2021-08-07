import java.util.Scanner;

public class countInversion {
    public static void main(String args[]) {
        int n;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter size\n");
        n = scanner.nextInt();
        scanner.nextLine();
        int[] arr = new int[n];
        System.out.println("Enter array\n");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int inv = countInversions(arr, 0, n-1);
        System.out.println("Total inversions in array are :" + inv);

        scanner.close();
    }

    public static int countInversions(int arr[], int low, int high) {
        int inv = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            inv += countInversions(arr, low, mid);
            inv += countInversions(arr, mid + 1, high);
            inv += merge(arr, low, mid, high);
        }

        return inv;

    }

    public static int merge(int arr[], int low, int mid, int high) {
        int inv = 0;
        int i = 0, j = 0, k = low;
        int[] a = new int[mid - low+1];
        int[] b = new int[high - mid ];

        for (int z = 0; z < a.length; z++) {

            a[z] = arr[z + low];
        }
        for (int z = 0; z < b.length; z++) {

            b[z] = arr[z + mid + 1];
        }
        while (i < mid && j < high) {
            System.out.println("**");
            if (a[i] < b[j]) {
                arr[k] = a[i];
                i++;
                k++;
            } else {
                
                arr[k] = b[j];
                inv += a.length - i;
                k++;
                j++;
            }

        }

        while (i < a.length) {
            arr[k] = a[i];
            k++;
            i++;
        }
        while (j < b.length) {
            arr[k] = b[j];
            k++;
            j++;
        }
        System.out.println("--"+arr[0]);
        return inv;
    }
}