import java.util.*;

abstract class absarea
{
	abstract void areac(double r);
	abstract void arear(int l, int b);
	abstract void areas(int s);
}
class calc extends absarea
{
	void areac(double r)
	{
		System.out.println("Area of circle:"+(3.14*r*r));
	}
	void arear(int l, int b)
	{
		System.out.println("Area of rectangle:"+(l*b));
	}
	void areas(int s)
	{
		System.out.println("Area of square:"+(s*s));
	}
}
class abs
{
	public static void main(String[] args) 
	{
		calc c = new calc();
		c.areac(2.1);
		c.arear(2,2);
		c.areas(2);
	}
}
