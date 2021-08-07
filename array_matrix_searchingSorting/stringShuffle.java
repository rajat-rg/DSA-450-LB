import java.util.Scanner;

class stringShufle {
    public static void main(String args[]) {
        String a = new String();
        String b = new String();
        String s = new String();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter String 1: ");
        a = scanner.nextLine();
        System.out.print("Enter String 2: ");
        b = scanner.nextLine();
        System.out.print("Enter shuffled String: ");
        s = scanner.nextLine();
        isValid(a, b, s);

        scanner.close();
    }

    private static void isValid(String a, String b, String s) {
        int i = 0, j = 0, k = 0;
        if (s.length() == a.length() + b.length()) {
            while (k < s.length() - 1) {
                if (s.charAt(k) == a.charAt(i)) {
                    k++;
                    i++;
                } else if (s.charAt(k) == b.charAt(j)) {
                    k++;
                    j++;
                } else
                    System.out.println("Not a valid shuffle");
            }
            System.out.println("It's a valid shuffled string");

        } else
            System.out.println("Not a valid shuffle");
    }
}