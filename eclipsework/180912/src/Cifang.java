import java.util.Arrays;

public class Cifang {

	public static double Power(double base, int exponent) {
		double ret = base;
		boolean flag = false;
		if(exponent == 0)
			return 1;
		if(exponent < 0) {
			flag = true;
			exponent = -exponent;
		}
		while (--exponent > 0) {
			ret *= base;
		}
		if(flag)
			return 1.0/ret;
		else
			return ret;
	}
	
	//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
	//所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
	public static void reOrderArray(int [] array) {
        //首先寻找第一个奇数，并将其放在0号位置。然后将第一个奇数之前的元素全部往后移一位。
        //依次在第一个奇数之后的元素中寻找奇数，并做移动操作。就可以保证原来的相对顺序
        int j=0;//记录第一个为奇数的位置
        int m=0;//记录排好序的奇数的最后一个位置
        for(int i=0;i<array.length;i++)
        {    
            if(array[i]%2==1)//找到第一个奇数
            {
                int temp = array[i];//记录第一个奇数
                int ti=i;
                for(;ti>0;ti--)
                {
                    array[ti]=array[ti-1];//将第一个奇数之前的所有元素往后移一个位置
                }
                array[0] = temp;//将第一个奇数放到array[0]位置
                j=i;
                break;
            }
        }
        for(++j;j<array.length;j++)//依次寻找剩余的奇数
        {
            if(array[j]%2==1)
            {
                int temp = array[j];
                int tj = j;
                for(;tj>m;tj--)
                {
                    array[tj]=array[tj-1];
                }
                array[++m]=temp;
            }
        }
        
        
        
    }

	public static void main(String[] args) {
		int arr[]= {1, 2, 3, 4, 5, 6,7};
		System.out.println(Arrays.toString(arr));
		reOrderArray(arr);
		System.out.println(Arrays.toString(arr));
	}
}
