import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Stack<Integer> a = new Stack<>();
        Stack<Integer> b = new Stack<>();
        Stack<Integer> c = new Stack<>();
        ArrayList<String> res = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            a.push(num);
        }

        try{
        while (!b.empty() || !a.empty()) {
            int si = res.size();

            if (c.empty()) {
                if (!a.empty() && a.peek() != 1) {
                    res.add("A B");
                    b.push(a.peek());
                    a.pop();
                } else {
                    res.add("A C");
                    c.push(a.peek());
                    a.pop();
                }
            } else {
                if (a.peek() != c.peek() + 1 && b.peek() != c.peek() + 1) {
                    res.add("A B");
                    b.push(a.peek());
                    a.pop();
                } else if (a.peek() == c.peek() + 1) {
                    res.add("A C");
                    c.push(a.peek());
                    a.pop();
                } else if (b.peek() == c.peek() + 1) {
                    res.add("B C");
                    c.push(b.peek());
                    b.pop();
                }
            }
        }
    }
    catch (Exception e){
        System.out.println(-1);
        return;
    }

        System.out.println(res.size());
        for (String s : res) {
            System.out.println(s);
        }
    }
}
