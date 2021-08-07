class SearchInSortedRotated
{
    public static void main(String args[] )
    {
        // int n;
        // Scanner scan = new Scanner(System.in);
        // n = scan.nextInt();
        // scan.nextLine();
        int arr[] = {10,12,34, 1,2,3,4,5,6,7,8,9};
        int key= 34;
        int s = searchinrotated(arr,key);
        System.out.println(s);
        s = minInarray(arr);
        System.out.println(s);
        s = maxInarray(arr);
        System.out.println(s);
    }
    private static int searchinrotated(int arr[], int key) {
        int l=0;
        int h = arr.length-1;
        while(l < h)
        {
            int mid = (l+h)/2;
            if(key== arr[mid])
            return mid;

            if(arr[mid]> arr[l]){
                if(key< arr[mid] && key>=arr[l])
                {
                    h=mid-1;

                }
                else
                l = mid+1;
            }
            else
            {
                if(key<= arr[h] && key > arr[mid])
                {
                    l = mid+1;
                }
                else
                h=mid-1;
                
            }
        }
        
        return -1;
    }

    private static int minInarray(int arr[])
    {
        int l =0; 
        int h = arr.length-1;
        while(l<h)
        {
            int mid = (l+h)/2;
            if(arr[mid] < arr[mid-1] && mid >0)
            return arr[mid];

            else if (arr[l]<= arr[mid] && arr[mid]> arr[h])
            l = mid+1;
            else
            h=mid-1;
        }
        return arr[l];
    }
    private static int maxInarray(int arr[])
    {
        int l =0; 
        int h = arr.length-1;
        while(l<h)
        {
            int mid = (l+h)/2;
            if(arr[mid] > arr[mid-1] && mid >0)
            return arr[mid];

            else if (arr[l]>= arr[mid] && arr[mid]< arr[h])
            l = mid+1;
            else
            h=mid-1;
        }
        return arr[l];
    }

}