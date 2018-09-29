import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Test {
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("a.txt"),true));
		bw.write("Hello");
		bw.newLine();
		bw.close();
	}
}
