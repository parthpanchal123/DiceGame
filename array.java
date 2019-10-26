import java.util.*;

class array
{
    public static void main(String[] args)
    {
        int n,a[],s=0,m=0,temp;
        a = new int[10];
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i = 0;i < n;i++)
        {
            a[i]=sc.nextInt();
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = a[j];
                }
            }
        }
        for(int i = 0;i < n;i++)
        {
            s = s + a[i];
            m = a[i];
        }
        m = s % m;
        System.out.println("Remainder:"+m);
    }
}