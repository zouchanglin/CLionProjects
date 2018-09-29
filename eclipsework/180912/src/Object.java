
public class Object {
	//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
	public static void main(String[] args) {
		long num = (-2147483648)&0x0FFFFFFFF;
		
		int count = 0;
//		for (int i = 0; i < 32; i++) {
//			if (num % 2 == 1) {
//				count++;
//			}
//			num = num / 2;
//		}
//		System.out.println(count);
		
		while(num>0) {
			num = num&(num-1);
			count++;
		}
		System.out.println(count);
	}
}
