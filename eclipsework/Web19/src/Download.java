package com.xpu.content;
 
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URLEncoder;
 
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import sun.misc.BASE64Encoder;
 
public class DownloadServlet2 extends HttpServlet {
 
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// 这个主要是下载中文的
		// 获取要下载的文件的名称
		String filename = request.getParameter("filename");
		// 解决获得中文参数的乱码
		filename = new String(filename.getBytes("ISO8859-1"), "UTF-8");
		// 设置头信息
		response.setContentType(getServletContext().getMimeType(filename));
		String agent = request.getHeader("User-Agent");
		String filenameEncoder = "";
		if (agent.contains("MSIE")) {
			// IE浏览器
			filenameEncoder = URLEncoder.encode(filename, "utf-8");
			filenameEncoder = filename.replace("+", " ");
		} else if (agent.contains("Firefox")) {
			// 火狐浏览器
			BASE64Encoder base64Encoder = new BASE64Encoder();
			filenameEncoder = "=?utf-8?B?" + base64Encoder.encode(filename.getBytes("utf-8")) + "?=";
		} else {
			// 其它浏览器
			filenameEncoder = URLEncoder.encode(filename, "utf-8");
		}
 
		response.setHeader("Content-Disposition", "attachment;filename=" + filenameEncoder);
		System.out.println(filename);
		// 获取文件的绝对路径
		String path = getServletContext().getRealPath("/download/" + filename);
		// 获取该文件的输入流
		InputStream is = new FileInputStream(path);
		// 获取输出流
		ServletOutputStream os = response.getOutputStream();
		// 文件拷贝的模板代码
		int len = 0;
		byte[] bys = new byte[1024];
		while ((len = is.read(bys)) != -1) {
			os.write(bys, 0, len);
		}
		is.close();
	}
 
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
 
}
